//
// Created by karaler on 2019/12/30.
// Author: karaler
// Description: 
// Others: 
// Copyright (c) 2019 Bytelang . All rights reserved.
//

#include "KPVideoShowTextPlugin.h"

KPVideoShowTextPlugin::KPVideoShowTextPlugin(const std::string &identify_name, PluginParams params) : KPPluginAdapter(std::move(identify_name)) {
    // 赋值信息
    filter_type = KP_FILTER_TYPE_VIDEO;
    filter_name = "video_plugin_show_text";

    // 赋值described
    std::stringstream filter_desc_stream;

    std::string font_size  = "17";
    std::string font_color = "white";
    std::string text       = "未设置text";
    std::string x          = "0";
    std::string y          = "0";
    if (params.find("font_size") != params.end()) {
        font_size = params["font_size"];
    }
    if (params.find("font_color") != params.end()) {
        font_color = params["font_color"];
    }
    if (params.find("text") != params.end()) {
        text = params["text"];
    }
    if (params.find("x") != params.end()) {
        x = params["x"];
    }
    if (params.find("y") != params.end()) {
        y = params["y"];
    }

    filter_desc_stream << "x=" << x << ":y=" << y << ":fontfile=Res/font.ttf:fontsize=" << font_size << ":fontcolor=" << font_color << ":text='" << text << "'";
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
        return new KPVideoShowTextPlugin("kplayer", std::move(params));
}
