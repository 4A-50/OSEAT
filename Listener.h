//////////////////////////////////////////////////////////////////////////////////
// Very Little Has Been Changed From The Example Program, In An Attempt To Make //
// It Easier To Understand And Add Any Extra Bits Down The Line.                //
//////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "fit_decode.hpp"
#include "fit_mesg_broadcaster.hpp"
#include "fit_developer_field_description.hpp"
#include "core.h"

#include <iostream>
class Listener
    : public fit::FileIdMesgListener
    , public fit::UserProfileMesgListener
    , public fit::MonitoringMesgListener
    , public fit::DeviceInfoMesgListener
    , public fit::MesgListener
    , public fit::LapMesgListener
    , public fit::DeveloperFieldDescriptionListener
    , public fit::RecordMesgListener
{
    public:

        Listener() = default;

        static void PrintValues(const fit::FieldBase& field);

        float ConvertValues(const fit::FieldBase& field);

        void OnMesg(fit::Mesg& mesg);

        void OnMesg(fit::LapMesg& mesg);

        void OnMesg(fit::FileIdMesg& mesg);

        void OnMesg(fit::UserProfileMesg& mesg);

        void OnMesg(fit::DeviceInfoMesg& mesg);

        void OnMesg(fit::MonitoringMesg& mesg);

        static void PrintOverrideValues(const fit::Mesg& mesg, FIT_UINT8 fieldNum);

        void OnMesg(fit::RecordMesg& record) override;

        void OnDeveloperFieldDescription(const fit::DeveloperFieldDescription& desc) override;
};