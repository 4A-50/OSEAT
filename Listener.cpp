#include "Listener.h"

void Listener::PrintValues(const fit::FieldBase& field)
{
    for (FIT_UINT8 j = 0; j < (FIT_UINT8)field.GetNumValues(); j++)
    {
        //std::wcout << L"       Val" << j << L": ";
        switch (field.GetType())
        {
            // Get float 64 values for numeric types to receive values that have
            // their scale and offset properly applied.
        case FIT_BASE_TYPE_ENUM:
        case FIT_BASE_TYPE_BYTE:
        case FIT_BASE_TYPE_SINT8:
        case FIT_BASE_TYPE_UINT8:
        case FIT_BASE_TYPE_SINT16:
        case FIT_BASE_TYPE_UINT16:
        case FIT_BASE_TYPE_SINT32:
        case FIT_BASE_TYPE_UINT32:
        case FIT_BASE_TYPE_SINT64:
        case FIT_BASE_TYPE_UINT64:
        case FIT_BASE_TYPE_UINT8Z:
        case FIT_BASE_TYPE_UINT16Z:
        case FIT_BASE_TYPE_UINT32Z:
        case FIT_BASE_TYPE_UINT64Z:
        case FIT_BASE_TYPE_FLOAT32:
        case FIT_BASE_TYPE_FLOAT64:
            std::wcout << field.GetFLOAT64Value(j);
            break;
        case FIT_BASE_TYPE_STRING:
            std::wcout << field.GetSTRINGValue(j) << "string ";
            break;
        default:
            break;
        }
        std::wcout << L" " << field.GetUnits().c_str() << L"\n";;
    }
}

float Listener::ConvertValues(const fit::FieldBase& field)
{
    for (FIT_UINT8 j = 0; j < (FIT_UINT8)field.GetNumValues(); j++)
    {
        return field.GetFLOAT64Value(j);
    }
}

void Listener::OnMesg(fit::LapMesg& mesg)
{
    LapData newLap;

    for (FIT_UINT16 i = 0; i < (FIT_UINT16)mesg.GetNumFields(); i++)
    {
        fit::Field* field = mesg.GetFieldByIndex(i);

        if (field->GetName() == "total_timer_time")
        {
            newLap.totalTime = ConvertValues(*field);
        }
        else if (field->GetName() == "total_distance")
        {
            newLap.totalDistance = ConvertValues(*field);
        }
    }

    Core::fileData.laps.push_back(newLap);
}

void Listener::OnMesg(fit::Mesg& mesg)
{
    /*printf("On Mesg:\n");
    std::wcout << L"   New Mesg: " << mesg.GetName().c_str() << L".  It has " << mesg.GetNumFields() << L" field(s) and " << mesg.GetNumDevFields() << " developer field(s).\n";

    for (FIT_UINT16 i = 0; i < (FIT_UINT16)mesg.GetNumFields(); i++)
    {
        fit::Field* field = mesg.GetFieldByIndex(i);
        std::wcout << L"   Field" << i << " (" << field->GetName().c_str() << ") has " << field->GetNumValues() << L" value(s)\n";
        PrintValues(*field);
    }

    for (auto devField : mesg.GetDeveloperFields())
    {
        std::wcout << L"   Developer Field(" << devField.GetName().c_str() << ") has " << devField.GetNumValues() << L" value(s)\n";
        PrintValues(devField);
    }*/

    for (FIT_UINT16 i = 0; i < (FIT_UINT16)mesg.GetNumFields(); i++)
    {
        fit::Field* field = mesg.GetFieldByIndex(i);

        ////
        // The Worlds Ugliest Way To Code This, Why Doesn't C++ Have Switch Statments For Strings!
        ////
        //Live Data
        if (field->GetName() == "timestamp")
        {
            Core::fileData.timestamp.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "position_lat")
        {
            Core::fileData.posLat.push_back(ConvertValues(*field) * (180 / std::pow(2, 31)));
        }
        else if (field->GetName() == "position_long")
        {
            Core::fileData.posLong.push_back(ConvertValues(*field) * (180 / std::pow(2, 31)));
        }
        else if (field->GetName() == "gps_accuracy")
        {
            Core::fileData.gpsAccuracy.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "altitude")
        {
            Core::fileData.altitude.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "grade")
        {
            Core::fileData.grade.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "distance")
        {
            Core::fileData.distance.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "heart_rate")
        {
            Core::fileData.heartRate.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "calories")
        {
            Core::fileData.calories.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "cadence")
        {
            Core::fileData.cadence.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "speed")
        {
            Core::fileData.speed.push_back((ConvertValues(*field) * 3.6));
        }
        else if (field->GetName() == "temperature")
        {
            Core::fileData.temp.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "ascent")
        {
            Core::fileData.ascent.push_back(ConvertValues(*field));
        }
        else if (field->GetName() == "descent")
        {
            Core::fileData.descent.push_back(ConvertValues(*field));
        }
        //Finalised Stats
        else if (field->GetName() == "start_time")
        {
            Core::fileData.startTime = ConvertValues(*field);
        }
        else if (field->GetName() == "total_elapsed_time")
        {
            Core::fileData.elapsedTime = ConvertValues(*field);
        }
        else if (field->GetName() == "total_timer_time")
        {
            Core::fileData.movingTime = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_speed")
        {
            Core::fileData.averageSpeed = (ConvertValues(*field) * 3.6);
        }
        else if (field->GetName() == "max_speed")
        {
            Core::fileData.maxSpeed = (ConvertValues(*field) * 3.6);
        }
        else if (field->GetName() == "total_distance")
        {
            Core::fileData.totalDistance = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_cadence")
        {
            Core::fileData.averageCadence = ConvertValues(*field);
        }
        else if (field->GetName() == "max_cadence")
        {
            Core::fileData.maxCadence = ConvertValues(*field);
        }
        else if (field->GetName() == "min_heart_rate")
        {
            Core::fileData.minHeartRate = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_heart_rate")
        {
            Core::fileData.averageHeartRate = ConvertValues(*field);
        }
        else if (field->GetName() == "max_heart_rate")
        {
            Core::fileData.maxHeartRate = ConvertValues(*field);
        }
        else if (field->GetName() == "min_altitude")
        {
            Core::fileData.minAltitude = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_altitude")
        {
            Core::fileData.averageAltitude = ConvertValues(*field);
        }
        else if (field->GetName() == "max_altitude")
        {
            Core::fileData.maxAltitude = ConvertValues(*field);
        }
        else if (field->GetName() == "max_neg_grade")
        {
            Core::fileData.maxNegativeGradient = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_grade")
        {
            Core::fileData.averageGradient = ConvertValues(*field);
        }
        else if (field->GetName() == "max_pos_grade")
        {
            Core::fileData.maxPositiveGradient = ConvertValues(*field);
        }
        else if (field->GetName() == "total_calories")
        {
            Core::fileData.totalCalories = ConvertValues(*field);
        }
        else if (field->GetName() == "avg_temperature")
        {
            Core::fileData.averageTemperature = ConvertValues(*field);
        }
        else if (field->GetName() == "max_temperature")
        {
            Core::fileData.maxTemperature = ConvertValues(*field);
        }
        else if (field->GetName() == "total_ascent")
        {
            Core::fileData.totalAscent = ConvertValues(*field);
        }
        else if (field->GetName() == "total_descent")
        {
            Core::fileData.totalDescent = ConvertValues(*field);
        }
    }
}

void Listener::OnMesg(fit::FileIdMesg& mesg)
{
    printf("File ID:\n");
    if (mesg.IsTypeValid())
        printf("   Type: %d\n", mesg.GetType());
    if (mesg.IsManufacturerValid())
        printf("   Manufacturer: %d\n", mesg.GetManufacturer());
    if (mesg.IsProductValid())
        printf("   Product: %d\n", mesg.GetProduct());
    if (mesg.IsSerialNumberValid())
        printf("   Serial Number: %u\n", mesg.GetSerialNumber());
    if (mesg.IsNumberValid())
        printf("   Number: %d\n", mesg.GetNumber());
}

void Listener::OnMesg(fit::UserProfileMesg& mesg)
{
    printf("User profile:\n");
    if (mesg.IsFriendlyNameValid())
        std::wcout << L"   Friendly Name: " << mesg.GetFriendlyName().c_str() << L"\n";
    if (mesg.GetGender() == FIT_GENDER_MALE)
        printf("   Gender: Male\n");
    if (mesg.GetGender() == FIT_GENDER_FEMALE)
        printf("   Gender: Female\n");
    if (mesg.IsAgeValid())
        printf("   Age [years]: %d\n", mesg.GetAge());
    if (mesg.IsWeightValid())
        printf("   Weight [kg]: %0.2f\n", mesg.GetWeight());
}

void Listener::OnMesg(fit::DeviceInfoMesg& mesg)
{
    printf("Device info:\n");

    if (mesg.IsTimestampValid())
        printf("   Timestamp: %d\n", mesg.GetTimestamp());

    switch (mesg.GetBatteryStatus())
    {
    case FIT_BATTERY_STATUS_CRITICAL:
        printf("   Battery status: Critical\n");
        break;
    case FIT_BATTERY_STATUS_GOOD:
        printf("   Battery status: Good\n");
        break;
    case FIT_BATTERY_STATUS_LOW:
        printf("   Battery status: Low\n");
        break;
    case FIT_BATTERY_STATUS_NEW:
        printf("   Battery status: New\n");
        break;
    case FIT_BATTERY_STATUS_OK:
        printf("   Battery status: OK\n");
        break;
    default:
        printf("   Battery status: Invalid\n");
        break;
    }
}

void Listener::OnMesg(fit::MonitoringMesg& mesg)
{
    printf("Monitoring:\n");

    if (mesg.IsTimestampValid())
    {
        printf("   Timestamp: %d\n", mesg.GetTimestamp());
    }

    if (mesg.IsActivityTypeValid())
    {
        printf("   Activity type: %d\n", mesg.GetActivityType());
    }

    switch (mesg.GetActivityType()) // The Cycling field is dynamic
    {
    case FIT_ACTIVITY_TYPE_WALKING:
    case FIT_ACTIVITY_TYPE_RUNNING: // Intentional fallthrough
        if (mesg.IsStepsValid())
        {
            printf("   Steps: %d\n", mesg.GetSteps());
        }
        break;
    case FIT_ACTIVITY_TYPE_CYCLING:
    case FIT_ACTIVITY_TYPE_SWIMMING: // Intentional fallthrough
        if (mesg.IsStrokesValid())
        {
            printf("Strokes: %d\n", mesg.GetStrokes());
        }
        break;
    default:
        if (mesg.IsCyclesValid())
        {
            printf("Cycles: %d\n", mesg.GetCycles());
        }
        break;
    }
}

void Listener::PrintOverrideValues(const fit::Mesg& mesg, FIT_UINT8 fieldNum)
{
    std::vector<const fit::FieldBase*> fields = mesg.GetOverrideFields(fieldNum);
    const fit::Profile::FIELD* profileField = fit::Profile::GetField(mesg.GetNum(), fieldNum);
    FIT_BOOL namePrinted = FIT_FALSE;

    for (const fit::FieldBase* field : fields)
    {
        if (!namePrinted)
        {
            printf("   %s:\n", profileField->name.c_str());
            namePrinted = FIT_TRUE;
        }

        if (FIT_NULL != dynamic_cast<const fit::Field*>(field))
        {
            // Native Field
            printf("      native: ");
        }
        else
        {
            // Developer Field
            printf("      override: ");
        }

        switch (field->GetType())
        {
            // Get float 64 values for numeric types to receive values that have
            // their scale and offset properly applied.
        case FIT_BASE_TYPE_ENUM:
        case FIT_BASE_TYPE_BYTE:
        case FIT_BASE_TYPE_SINT8:
        case FIT_BASE_TYPE_UINT8:
        case FIT_BASE_TYPE_SINT16:
        case FIT_BASE_TYPE_UINT16:
        case FIT_BASE_TYPE_SINT32:
        case FIT_BASE_TYPE_UINT32:
        case FIT_BASE_TYPE_SINT64:
        case FIT_BASE_TYPE_UINT64:
        case FIT_BASE_TYPE_UINT8Z:
        case FIT_BASE_TYPE_UINT16Z:
        case FIT_BASE_TYPE_UINT32Z:
        case FIT_BASE_TYPE_UINT64Z:
        case FIT_BASE_TYPE_FLOAT32:
        case FIT_BASE_TYPE_FLOAT64:
            printf("%f\n", field->GetFLOAT64Value());
            break;
        case FIT_BASE_TYPE_STRING:
            printf("%ls\n", field->GetSTRINGValue().c_str());
            break;
        default:
            break;
        }
    }
}

void Listener::OnMesg(fit::RecordMesg& record)
{
    printf("Record:\n");
    PrintOverrideValues(record, fit::RecordMesg::FieldDefNum::HeartRate);
    PrintOverrideValues(record, fit::RecordMesg::FieldDefNum::Cadence);
    PrintOverrideValues(record, fit::RecordMesg::FieldDefNum::Distance);
    PrintOverrideValues(record, fit::RecordMesg::FieldDefNum::Speed);
}

void Listener::OnDeveloperFieldDescription(const fit::DeveloperFieldDescription& desc)
{
    /*printf("New Developer Field Description\n");
    printf("   App Version: %d\n", desc.GetApplicationVersion());
    printf("   Field Number: %d\n", desc.GetFieldDefinitionNumber());*/
}