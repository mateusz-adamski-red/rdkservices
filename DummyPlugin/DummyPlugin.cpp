/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
*
* Copyright 2019 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include "DummyPlugin.h"

using namespace std;

namespace {
    void setResponseArray(JsonObject& response, const char* key, const vector<string>& items) {
    JsonArray arr;
    for(auto& i : items) arr.Add(JsonValue(i));

    response[key] = arr;

    string json;
    response.ToString(json);
}

constexpr const char EVENT_DUMMY_OBSERVER[] = "onDummyObserver";
}

namespace WPEFramework {
namespace Plugin {

    SERVICE_REGISTRATION(DummyPlugin, 1, 0);
    DummyPlugin* DummyPlugin::_instance = nullptr;

    DummyPlugin::DummyPlugin()
        : AbstractPlugin()
    {
        LOGINFO("DummyPlugin C'tor");
        DummyPlugin::_instance = this;

        registerMethod("getDummyValue", &DummyPlugin::getDummyValue, this);
        registerMethod("setDummyValue", &DummyPlugin::setDummyValue, this);

        // Initialize event mechanism
        InitializeIARM();
    }

    DummyPlugin::~DummyPlugin()
    {
        LOGINFO("DummyPlugin D'tor");
    }

    void FrontPanel::Deinitialize(PluginHost::IShell*)
    {
        DummyPlugin::_instance = nullptr;
        DeinitializeIARM();
    }

    uint32_t DummyPlugin::getDummyValue(const JsonObject& parameters, JsonObject& response) {
        LOGINFOMETHOD();

        // We can rasponse also an array (like json)
        // sample servicemanager response: {"success":true, "values":[value1:"yyy", value2:"zzz"]}
        setResponseArray(response, "values", values);

        // Need to return resposne everytime!
        returnResponse(0);
    }

    uint32_t DummyPlugin::setDummyValue(const JsonObject& parameters, JsonObject& response) {
        LOGINFOMETHOD();
        // Mandatory args
        returnIfParamNotFound(parameters, "value1");
        returnIfParamNotFound(parameters, "value2");

        string value1 = parameters["videoDisplay"].String();
        string value2 = parameters["resolution"].String();

        // Optional args
        bool hasOptionalValue = parameters.HasLabel("optionalValue");
        bool optionalValue = hasOptionalValue ? parameters["optionalValue"].Boolean() : true;
        LOGINFO("optionalValue set as %d: ", optionalValue);

        bool success = true;
        // We can also login error if some funtion can throw
        try
        {
            if (value1 == "Ala") {
                throw device::Exception();
            }
        }
        catch (const device::Exception& err)
        {
            LOG_DEVICE_EXCEPTION2(videoDisplay, resolution);
            success = false;
        }

        // Simulate event triggering
        IARM_Bus_PWRMgr_EventData_t _eventData;
        param.data.state.curState = 0;
        param.data.state.newState = 1;
        __TIMESTAMP();
        LOGINFO("%s:%d - DummyPluginTriggerEvent\r\n", __PRETTY_FUNCTION__,__LINE__);

        IARM_Bus_BroadcastEvent(IARM_BUS_PWRMGR_NAME,
                            (IARM_EventId_t)IARM_BUS_PWRMGR_EVENT_MODECHANGED,
                            (void *)&_eventData,
                            sizeof(_eventData));

        // Need to send response!
        returnResponse(success);
    }

    void DummyPlugin::observeDummyValue(onst JsonObject& parameters) {
        LOGINFO("observeDummyValue Called!");
        sendNotify(EVENT_DUMMY_OBSERVER, JsonObject());
    }

    void DisplaySettings::observeDummyValue(const char *owner, IARM_EventId_t eventId, void *data, size_t len) {
        // You can also check if event is correclty called by checking owner and eventId
        // EventId hold information about event type, so we can convert void* to some usefull data
        // if (strcmp(owner, IARM_BUS_PWRMGR_NAME)  == 0)
        // if (eventId == IARM_BUS_PWRMGR_EVENT_MODECHANGED )

        // *Owner describe the type of IARM_EVENT. For IARM_BUS_PWRMGR_NAME -> it will be _PWRMgr_EventId_t enum
        // For IARM_BUS_DSMGR_NAME -> it will be _DSMgr_EventId_t enum etc...
        //
        // typedef enum _PWRMgr_EventId_t {
        //     IARM_BUS_PWRMGR_EVENT_MODECHANGED = 0,            /*!< Event to notify power mode change */
        //     IARM_BUS_PWRMGR_EVENT_DEEPSLEEP_TIMEOUT,          /*!< Event to notify deepsleep timeout */
        //     IARM_BUS_PWRMGR_EVENT_RESET_SEQUENCE,             /*!< Event to notify progress of reset key sequence*/
        //     ...
        // }
        //
        // We can use switch to check what kind it is
        // switch (eventId) {
        //     case IARM_BUS_PWRMGR_EVENT_MODECHANGED:
        // }
        //

        // We can convert data* to specific data corresponding with event type
        if (eventId == IARM_BUS_PWRMGR_EVENT_MODECHANGED) {
            LOGINFO("Wrong type of event");
            return;
        }
        IARM_Bus_PWRMgr_EventData_t *param = (IARM_Bus_PWRMgr_EventData_t *)data;

        // We can log event state
        LOGINFO("ObserveDummyValue: Event IARM_BUS_PWRMGR_EVENT_MODECHANGED: State Changed %d -- > %d\r",
                param->data.state.curState, param->data.state.newState);

        if (DisplaySettings::_instance) {
            DisplaySettings::_instance->observeDummyValue();
        }
    }

    void DummyPlugin::InitializeIARM()
    {
        if (Utils::IARM::init())
        {
            IARM_Result_t res;
            LOGINFO("Register event");
            // During registration we need to provide 1: owner name | 2: event type (will be usefull for different data) | 3: methodName
            IARM_CHECK(IARM_Bus_RegisterEventHandler(IARM_BUS_PWRMGR_NAME, IARM_BUS_PWRMGR_EVENT_MODECHANGED, observeDummyValue));
        }
    }

    void DummyPlugin::::DeinitializeIARM()
    {
        if (Utils::IARM::isConnected())
        {
            IARM_Result_t res;
            LOGINFO("unregister event");
            IARM_CHECK(IARM_Bus_UnRegisterEventHandler(IARM_BUS_PWRMGR_NAME,IARM_BUS_PWRMGR_EVENT_MODECHANGED));
        }
    }

} // namespace Plugin
} // namespace WPEFramework
