//
// Created by karaler on 2019/12/30.
// Author: karaler
// Description: 
// Others: 
// Copyright (c) 2019 Bytelang . All rights reserved.
//

#ifndef KPLAYER_KPVIDEOSHOWTEXTPLUGIN_H
#define KPLAYER_KPVIDEOSHOWTEXTPLUGIN_H

#include "adapter/KPPluginAdapter.h"
#include "util/KPHelper.h"

#include "config.h"

extern "C" {
#include <libavutil/error.h>
}

#include <utility>

class KPVideoShowTextPlugin : public KPPluginAdapter {
public:
    explicit KPVideoShowTextPlugin(const std::string &identify_name, const std::string &filter_name, const KPFilterType &filter_type, PluginParamsObject plugin_params);
    ~KPVideoShowTextPlugin() override;
    void KillTask() override;
    void InitTask() override;
    void Task() override ;
};

// slot
extern "C" {
KPLAYER_PLUGIN_FUNC(KPVideoShowTextPlugin);
}


#endif //KPLAYER_KPVIDEOSHOWTEXTPLUGIN_H
