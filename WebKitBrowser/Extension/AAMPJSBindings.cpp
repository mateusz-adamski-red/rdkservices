/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
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
 */

#include "Module.h"
#include "AAMPJSBindings.h"

#include <JavaScriptCore/JavaScript.h>

extern "C" {
    void aamp_LoadJSController(JSGlobalContextRef context);
    void aamp_UnloadJSController(JSGlobalContextRef context);
    JSGlobalContextRef jscContextGetJSContext(JSCContext*);
}

namespace WPEFramework {
namespace JavaScript {
namespace AAMP {

namespace {

bool CanInjectJSBindings(const char* url) {

    if (url == nullptr)
        return false;

    if (g_strrstr(url, "://") == nullptr)
       return false;

    std::string hostStr;

    SoupURI* uri = soup_uri_new(url);
    if (uri) {
        hostStr = g_strdup(uri->host);
        soup_uri_free(uri);
    }

    if (hostStr.empty())
        return false;
    if (hostStr.find("youtube.com") != std::string::npos ||
        hostStr.find("atv-ext.amazon.com") != std::string::npos ||
        hostStr.find("ccast.api.amazonvideo.com") != std::string::npos ||
        hostStr.find("ccast.api.av-gamma.com") != std::string::npos)
        return false;

    return true;
}

}

void LoadJSBindings(WebKitScriptWorld* world, WebKitFrame* frame) {
    if (webkit_frame_is_main_frame(frame) == false)
        return;

    UnloadJSBindings(world, frame);

    const char* url = webkit_frame_get_uri(frame);
    bool canInject = CanInjectJSBindings(url);
    if (canInject) {
        JSCContext* jsContext = webkit_frame_get_js_context_for_script_world(frame, world);
        aamp_LoadJSController(jscContextGetJSContext(jsContext));
        g_object_unref(jsContext);

        g_object_set_data(G_OBJECT(world), "has-aamp", GINT_TO_POINTER(1));
    }
}

void UnloadJSBindings(WebKitScriptWorld* world, WebKitFrame* frame) {
    if (webkit_frame_is_main_frame(frame) == false)
        return;

    int p = GPOINTER_TO_INT(g_object_steal_data(G_OBJECT(world), "has-aamp"));
    if (p != 1)
        return;

    JSCContext* jsContext = webkit_frame_get_js_context_for_script_world(frame, world);
    aamp_UnloadJSController(jscContextGetJSContext(jsContext));
    g_object_unref(jsContext);
}

}  // namespace AAMP
}  // namespace JavaScript
}  // namespace WPEFramework
