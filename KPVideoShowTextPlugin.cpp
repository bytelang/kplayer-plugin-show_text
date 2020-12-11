//
// Created by karaler on 2019/12/30.
// Author: karaler
// Description: 
// Others: 
// Copyright (c) 2019 Bytelang . All rights reserved.
//

#include "KPVideoShowTextPlugin.h"

KPVideoShowTextPlugin::KPVideoShowTextPlugin(const std::string &identify_name, const std::string &filter_name, const KPFilterType &filter_type, PluginParamsObject plugin_params_object) : KPPluginAdapter(identify_name, filter_name, filter_type, plugin_params_object) {
    // 赋值described
    std::stringstream filter_desc_stream;

    std::string font_size  = "17";
    std::string font_color = "white";
    std::string text       = "未设置text";
    std::string x          = "0";
    std::string y          = "0";
    if (plugin_params_object.params.find("font_size") != plugin_params_object.params.end()) {
        font_size = plugin_params_object.params["font_size"];
    }
    if (plugin_params_object.params.find("font_color") != plugin_params_object.params.end()) {
        font_color = plugin_params_object.params["font_color"];
    }
    if (plugin_params_object.params.find("text") != plugin_params_object.params.end()) {
        text = plugin_params_object.params["text"];
    }
    if (plugin_params_object.params.find("x") != plugin_params_object.params.end()) {
        x = plugin_params_object.params["x"];
    }
    if (plugin_params_object.params.find("y") != plugin_params_object.params.end()) {
        y = plugin_params_object.params["y"];
    }

    filter_desc_stream << "x=" << x << ":y=" << y << ":fontfile=res/font.ttf:fontsize=" << font_size << ":fontcolor=" << font_color << ":text='" << text << "'";
    filter_desc = filter_desc_stream.str();

    // 查找过滤器
    filter = avfilter_get_by_name("drawtext");
    if (filter == nullptr)
        throw KPFilterException("未知过滤器; filter name: drawtext");
}

KPVideoShowTextPlugin::~KPVideoShowTextPlugin() {
}

void KPVideoShowTextPlugin::KillTask() {
}

void KPVideoShowTextPlugin::InitTask() {
}

void KPVideoShowTextPlugin::Task() {

}

KPLAYER_PLUGIN_FUNC(KPVideoShowTextPlugin) {
    return new KPVideoShowTextPlugin("kplayer", "video_plugin_show_text", KP_FILTER_TYPE_VIDEO, std::move(plugin_params));
}
