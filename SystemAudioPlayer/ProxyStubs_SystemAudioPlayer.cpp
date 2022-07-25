//
// 
//
// implements RPC proxy stubs for:
//   - class ISystemAudioPlayer
//   - class ISystemAudioPlayer::INotification
//

#include "ISystemAudioPlayer.h"
#include "Module.h"

namespace WPEFramework {

namespace ProxyStubs {

    using namespace Exchange;

    // -----------------------------------------------------------------
    // STUB
    // -----------------------------------------------------------------

    //
    // ISystemAudioPlayer interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Register(ISystemAudioPlayer::INotification*) = 0
    //  (2) virtual void Unregister(ISystemAudioPlayer::INotification*) = 0
    //  (3) virtual uint32_t Open(const string &input, string &output /* @out */) = 0;
    //  (4) virtual uint32_t Play(const string &input, string &output /* @out */) = 0;
    //  (5) virtual uint32_t PlayBuffer(const string &input, string &output /* @out */) = 0;
    //  (6) virtual uint32_t Pause(const string &input, string &output /* @out */) = 0;
    //  (7) virtual uint32_t Resume(const string &input, string &output /* @out */) = 0;
    //  (8) virtual uint32_t Stop(const string &input, string &output /* @out */) = 0;
    //  (9) virtual uint32_t Close(const string &input, string &output /* @out */) = 0;
    //  (10) virtual uint32_t SetMixerLevels(const string &input, string &output /* @out */) = 0;
    //  (11) virtual uint32_t SetSmartVolControl(const string &input, string &output /* @out */) = 0;
    //  (12) virtual uint32_t IsPlaying(const string &input, string &output /* @out */) = 0;  
    //

    ProxyStub::MethodHandler SystemAudioPlayerStubMethods[] = {
        // virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            SYSLOG(Trace::Error, (_T("[MY_LOGG] [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message)")));
            RPC::Data::Input& input(message->Parameters());
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] create input")));

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            RPC::instance_id param0 = reader.Number<RPC::instance_id>();
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Read params"));
            PluginHost::IShell* param0_proxy = nullptr;
            ProxyStub::UnknownProxy* param0_proxy_inst = nullptr;
            if (param0 != 0) {
                if ((param0_proxy_inst == nullptr)
                    SYSLOG(Trace::Error, (_T(, "[MY_LOGG] param0_proxy_inst == nullptr")));
                }
                if ((param0_proxy == nullptr) {
                    SYSLOG(Trace::Error, (_T(, "[MY_LOGG] param0_proxy == nullptr")));
                }

                param0_proxy_inst = RPC::Administrator::Instance().ProxyInstance(channel, param0, false, param0_proxy);
                ASSERT((param0_proxy_inst != nullptr) && (param0_proxy != nullptr) && "Failed to get instance of PluginHost::IShell proxy");

                if ((param0_proxy_inst == nullptr) || (param0_proxy == nullptr)) {
                    TRACE_L1("Failed to get instance of PluginHost::IShell proxy");
                }
            }

            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Write return value")));
            // write return value
            RPC::Data::Frame::Writer writer(message->Response().Writer());
             SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Finish write return value")));

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Get implementation")));
            if (!implementation) {
                SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Implementation is nullptr!!!")));
            }
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Call implementation->Configure")));
            const uint32_t output = implementation->Configure(param0_proxy);
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Finish calling implementation->Configure!")));
            writer.Number<const uint32_t>(output);
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Write output")));

            if (param0_proxy_inst != nullptr) {
                SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Release")));
                RPC::Administrator::Instance().Release(param0_proxy_inst, message->Response());
            }
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Finish function")));
        },

        // virtual void Register(ISystemAudioPlayer::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            RPC::instance_id param0 = reader.Number<RPC::instance_id>();
            ISystemAudioPlayer::INotification* param0_proxy = nullptr;
            ProxyStub::UnknownProxy* param0_proxy_inst = nullptr;
            if (param0 != 0) {
                param0_proxy_inst = RPC::Administrator::Instance().ProxyInstance(channel, param0, false, param0_proxy);
                ASSERT((param0_proxy_inst != nullptr) && (param0_proxy != nullptr) && "Failed to get instance of ISystemAudiPlayer::INotification proxy");

                if ((param0_proxy_inst == nullptr) || (param0_proxy == nullptr)) {
                    TRACE_L1("Failed to get instance of ISystemAudioPlayer::INotification proxy");
                }
            }

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            implementation->Register(param0_proxy);

            if (param0_proxy_inst != nullptr) {
                RPC::Administrator::Instance().Release(param0_proxy_inst, message->Response());
            }
        },

        // virtual void Unregister(ISystemAudioPlayer::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            RPC::instance_id param0 = reader.Number<RPC::instance_id>();
            ISystemAudioPlayer::INotification* param0_proxy = nullptr;
            ProxyStub::UnknownProxy* param0_proxy_inst = nullptr;
            if (param0 != 0) {
                param0_proxy_inst = RPC::Administrator::Instance().ProxyInstance(channel, param0, false, param0_proxy);
                ASSERT((param0_proxy_inst != nullptr) && (param0_proxy != nullptr) && "Failed to get instance of ISystemAudioPlayer::INotification proxy");

                if ((param0_proxy_inst == nullptr) || (param0_proxy == nullptr)) {
                    TRACE_L1("Failed to get instance of ISystemAudioPlayer::INotification proxy");
                }
            }

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            implementation->Unregister(param0_proxy);

            if (param0_proxy_inst != nullptr) {
                RPC::Administrator::Instance().Release(param0_proxy_inst, message->Response());
            }
        },

        // virtual uint32_t Open(const string &input, string &output /* @out */)
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Open(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t Play(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Play(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t PlayBuffer(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->PlayBuffer(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t Pause(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Pause(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t Resume(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Resume(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t Stop(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Stop(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t Close(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Close(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t SetMixerLevels(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->SetMixerLevels(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t SetSmartVolControl(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->SetSmartVolControl(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t IsPlaying(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->IsPlaying(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

         // virtual uint32_t Config(const string &input, string &output /* @out */)
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->Config(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        // virtual uint32_t GetPlayerSessionId(const string &input, string &output /* @out */)
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();
            string param1{}; // storage

            // call implementation
            ISystemAudioPlayer* implementation = reinterpret_cast<ISystemAudioPlayer*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer implementation pointer");
            const uint32_t output = implementation->GetPlayerSessionId(param0, param1);

            // write return values
            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<const uint32_t>(output);
            writer.Text(param1);
        },

        nullptr
    }; // SystemAudioPlayerStubMethods[]

    //
    // ISystemAudioPlayer::INotification interface stub definitions
    //
    // Methods:
    // virtual void OnSAPEvents(const string &data) = 0;       
    //

    ProxyStub::MethodHandler SystemAudioPlayerNotificationStubMethods[] = {
        // virtual void OnSAPEvents(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel VARIABLE_IS_NOT_USED, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::Data::Input& input(message->Parameters());

            // read parameters
            RPC::Data::Frame::Reader reader(input.Reader());
            const string param0 = reader.Text();

            // call implementation
            ISystemAudioPlayer::INotification* implementation = reinterpret_cast<ISystemAudioPlayer::INotification*>(input.Implementation());
            ASSERT((implementation != nullptr) && "Null ISystemAudioPlayer::INotification implementation pointer");
            implementation->OnSAPEvents(param0);
        },
        
        nullptr
    }; // SystemAudioPlayerNotificationStubMethods[]

    // -----------------------------------------------------------------
    // PROXY
    // -----------------------------------------------------------------

    //
    // ISystemAudioPlayer interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Register(ITextToSpeech::INotification*) = 0
    //  (2) virtual void Unregister(ITextToSpeech::INotification*) = 0
    //  (3) virtual uint32_t Enable(const string&, string&) = 0
    //  (4) virtual uint32_t ListVoices(const string&, string&) = 0
    //  (5) virtual uint32_t SetConfiguration(const string&, string&) = 0
    //  (6) virtual uint32_t GetConfiguration(const string&, string&) = 0
    //  (7) virtual uint32_t IsEnabled(const string&, string&) = 0
    //  (8) virtual uint32_t Speak(const string&, string&) = 0
    //  (9) virtual uint32_t Cancel(const string&, string&) = 0
    //  (10) virtual uint32_t Pause(const string&, string&) = 0
    //  (11) virtual uint32_t Resume(const string&, string&) = 0
    //  (12) virtual uint32_t IsSpeaking(const string&, string&) = 0
    //  (13) virtual uint32_t GetSpeechState(const string&, string&) = 0
    //

    class SystemAudioPlayerProxy final : public ProxyStub::UnknownProxyType<ISystemAudioPlayer> {
    public:
        SystemAudioPlayerProxy(const Core::ProxyType<Core::IPCChannel>& channel, RPC::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Configure(PluginHost::IShell* param0) override
        {
            IPCMessage newMessage(BaseClass::Message(0));
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] uint32_t Configure(PluginHost::IShell* param0) override:")));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Number<RPC::instance_id>(RPC::instance_cast<PluginHost::IShell*>(param0));

            // invoke the method handler
            uint32_t output{};
            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] InvokeMethod")));
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return value
                SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Finish Invoke without error")));
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Reader")));
                output = reader.Number<uint32_t>();
                SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Complete")));
                Complete(reader);
            }

            SYSLOG(Trace::Error, (_T(, "[MY_LOGG] Return output")));
            return output;
        }

        void Register(ISystemAudioPlayer::INotification* param0) override
        {
            IPCMessage newMessage(BaseClass::Message(1));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Number<RPC::instance_id>(RPC::instance_cast<ISystemAudioPlayer::INotification*>(param0));

            // invoke the method handler
            if (Invoke(newMessage) == Core::ERROR_NONE) {
                // read return value
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                Complete(reader);
            }
        }

        void Unregister(ISystemAudioPlayer::INotification* param0) override
        {
            IPCMessage newMessage(BaseClass::Message(2));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Number<RPC::instance_id>(RPC::instance_cast<ISystemAudioPlayer::INotification*>(param0));

            // invoke the method handler
            if (Invoke(newMessage) == Core::ERROR_NONE) {
                // read return value
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                Complete(reader);
            }
        }
        
         uint32_t Open(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(3));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t Play(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(4));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t PlayBuffer(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(5));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t Pause(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(6));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t Resume(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(7));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t Stop(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(8));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t Close(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(9));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t SetMixerLevels(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(10));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

        uint32_t SetSmartVolControl(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(11));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

       
        uint32_t IsPlaying(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(12));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }

         uint32_t Config(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(13));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }
    
        uint32_t GetPlayerSessionId(const string& param0, string& /* out */ param1) override
        {
            IPCMessage newMessage(BaseClass::Message(14));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            uint32_t output{};
            if ((output = Invoke(newMessage)) == Core::ERROR_NONE) {
                // read return values
                RPC::Data::Frame::Reader reader(newMessage->Response().Reader());
                output = reader.Number<uint32_t>();
                param1 = reader.Text();
            }

            return output;
        }


    }; // class SystemAudioPlayerProxy

    //
    // ISystemAudioPlayer::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnSAPEvents(const string&) = 0
    //

    class SystemAudioPlayerNotificationProxy final : public ProxyStub::UnknownProxyType<ISystemAudioPlayer::INotification> {
    public:
        SystemAudioPlayerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, RPC::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void OnSAPEvents(const string& param0) override
        {
            IPCMessage newMessage(BaseClass::Message(0));

            // write parameters
            RPC::Data::Frame::Writer writer(newMessage->Parameters().Writer());
            writer.Text(param0);

            // invoke the method handler
            Invoke(newMessage);
        }
        
    }; // class SystemAudioPlayerNotificationProxy

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<ISystemAudioPlayer, SystemAudioPlayerStubMethods> SystemAudioPlayerStub;
        typedef ProxyStub::UnknownStubType<ISystemAudioPlayer::INotification, SystemAudioPlayerNotificationStubMethods> SystemAudioPlayerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<ISystemAudioPlayer, SystemAudioPlayerProxy, SystemAudioPlayerStub>();
                RPC::Administrator::Instance().Announce<ISystemAudioPlayer::INotification, SystemAudioPlayerNotificationProxy, SystemAudioPlayerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<ISystemAudioPlayer>();
                RPC::Administrator::Instance().Recall<ISystemAudioPlayer::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
