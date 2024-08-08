// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "in_app_purchase_tizen_plugin.h"

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <string>

#include "log.h"

// InAppPurchaseTizenPlugin is disabled because it causes the Tizen app to crash
// on startup without any error. The reason for the crash currently is unknown.
// Below code heavily cuts down the original code to make app work.
// The original code is in the master branch.
namespace {

    const char *kInvalidArgument = "Invalid argument";

    class InAppPurchaseTizenPlugin : public flutter::Plugin {
    public:
        static void RegisterWithRegistrar(flutter::PluginRegistrar *plugin_registrar);

        InAppPurchaseTizenPlugin() {}

        virtual ~InAppPurchaseTizenPlugin() {}

    private:
        void HandleMethodCall(
                const flutter::MethodCall <flutter::EncodableValue> &method_call,
                std::unique_ptr <flutter::MethodResult<flutter::EncodableValue>> result);
    };

    void InAppPurchaseTizenPlugin::RegisterWithRegistrar(
            flutter::PluginRegistrar *plugin_registrar) {
        auto channel =
                std::make_unique < flutter::MethodChannel < flutter::EncodableValue >> (
                        plugin_registrar->messenger(),
                                "plugins.flutter.tizen.io/in_app_purchase",
                                &flutter::StandardMethodCodec::GetInstance());

        auto plugin = std::make_unique<InAppPurchaseTizenPlugin>();

        channel->SetMethodCallHandler(
                [plugin_pointer = plugin.get()](const auto &call, auto result) {
                    plugin_pointer->HandleMethodCall(call, std::move(result));
                });

        plugin_registrar->AddPlugin(std::move(plugin));
    }

    void InAppPurchaseTizenPlugin::HandleMethodCall(
            const flutter::MethodCall <flutter::EncodableValue> &method_call,
            std::unique_ptr <flutter::MethodResult<flutter::EncodableValue>> result) {
        const auto &method_name = method_call.method_name();

        if (method_name == "getProductList" ||
            method_name == "getPurchaseList" ||
            method_name == "buyItem" ||
            method_name == "verifyInvoice" ||
            method_name == "isAvailable" ||
            method_name == "GetCustomId" ||
            method_name == "GetCountryCode") {
            // Silently succeed without performing any action
            result->Success(flutter::EncodableValue());
        } else {
            result->NotImplemented();
        }
    }

}

void InAppPurchaseTizenPluginRegisterWithRegistrar(
        FlutterDesktopPluginRegistrarRef registrar) {
    InAppPurchaseTizenPlugin::RegisterWithRegistrar(
            flutter::PluginRegistrarManager::GetInstance()
                    ->GetRegistrar<flutter::PluginRegistrar>(registrar));
}
