/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
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
**/

#include "gtest/gtest.h"

#include "AVInput.h"
#include "Source/WorkerPoolImplementation.h"

namespace RdkServicesTest {

TEST(AVInput, TestServiceWhenDisabled) {
    auto _engine = WPEFramework::Core::ProxyType<WorkerPoolImplementation>::Create(2, WPEFramework::Core::Thread::DefaultStackSize(), 16);
    WPEFramework::Core::IWorkerPool::Assign(&(*_engine));
    _engine->Run();

    // create plugin
    auto avInput = WPEFramework::Core::ProxyType<WPEFramework::Plugin::AVInput>::Create();
    WPEFramework::Core::JSONRPC::Handler& handler = *avInput;

    // expect methods
    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Exists(_T("contentProtected")));
    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Exists(_T("currentVideoMode")));
    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Exists(_T("numberOfInputs")));

    WPEFramework::Core::JSONRPC::Connection connection(1, 0);

    string response;
    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Invoke(connection, _T("contentProtected"), _T(""), response));
    EXPECT_EQ(response, _T("{\"isContentProtected\":true,\"success\":true}"));

    EXPECT_EQ(WPEFramework::Core::ERROR_NONE,  handler.Invoke(connection, _T("currentVideoMode"),_T(""),response));
    EXPECT_EQ(response, _T("{\"message\":\"org.rdk.HdmiInput plugin is not ready\",\"success\":false}"));

    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Invoke(connection, _T("numberOfInputs"), _T(""), response));
    EXPECT_EQ(response, _T("{\"message\":\"org.rdk.HdmiInput plugin is not ready\",\"success\":false}"));

    // Initialize and activate plugin
    EXPECT_EQ(string(""), avInput->Initialize(nullptr));

    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Invoke(connection, _T("contentProtected"), _T(""), response));
    EXPECT_EQ(response, _T("{\"isContentProtected\":true,\"success\":true}"));

    EXPECT_EQ(WPEFramework::Core::ERROR_NONE,  handler.Invoke(connection, _T("currentVideoMode"),_T(""),response));
    EXPECT_EQ(response, _T("{\"currentVideoMode\":\"1080p60fps\",\"message\":\"Success\",\"success\":true}"));

    EXPECT_EQ(WPEFramework::Core::ERROR_NONE, handler.Invoke(connection, _T("numberOfInputs"), _T(""), response));
    EXPECT_EQ(response, _T("{\"numberOfInputs\":1,\"message\":\"Success\",\"success\":true}"));

    // cleanup
    avInput->Deinitialize(nullptr);

    WPEFramework::Core::IWorkerPool::Assign(nullptr);
    _engine.Release();
}

} // namespace RdkServicesTest
