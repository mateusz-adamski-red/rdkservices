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

#pragma once

#include "Module.h"
#include "AbstractPlugin.h"

namespace WPEFramework {
namespace Plugin {

    class DummyPlugin : public AbstractPlugin {
    public:
        DummyPlugin();
        virtual ~DummyPlugin();
        DummyPlugin(const DummyPlugin&) = delete;
        DummyPlugin& operator=(const DummyPlugin&) = delete;
        DummyPlugin(DummyPlugin&&) = default;
        DummyPlugin& operator=(DummyPlugin&&) = default;

        // Override from AbstractPlugin
        // Allow to call deinitialize before Plugin will be destructed
        virtual void Deinitialize(PluginHost::IShell) override;

    private:
        typedef Core::JSON::String JString;
        typedef Core::JSON::ArrayType<JString> JStringArray;
        typedef Core::JSON::Boolean JBool;

        //Begin methods
        uint32_t getDummyValue(const JsonObject& parameters, JsonObject& response);
        uint32_t setummyValue(const JsonObject& parameters, JsonObject& response);
        //End methods

        //Begin events
        void observeDummyValue(onst JsonObject& parameters);
        //End events

        // Static events, which will be triggered by IARM
        static void observeDummyValue(const char *owner, IARM_EventId_t eventId, void *data, size_t len);

        void InitializeIARM();
        void DeinitializeIARM();
    };

} // namespace Plugin
} // namespace WPEFramework
