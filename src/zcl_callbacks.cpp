#include "app_task.h"

#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/ConcreteAttributePath.h>

using namespace ::chip;
using namespace ::chip::app::Clusters;

void MatterPostAttributeChangeCallback(const chip::app::ConcreteAttributePath & attributePath, uint8_t mask, uint8_t type,
                                       uint16_t size, uint8_t * value)
{
        // if (attributePath.mClusterId != OnOff::Id || attributePath.mAttributeId != OnOff::Attributes::OnOff::Id)
        //         return;

        // GetAppTask().PostEvent(AppEvent(*value ? AppEvent::SensorActivate : AppEvent::SensorDeactivate));

    ClusterId clusterId = attributePath.mClusterId;
	AttributeId attributeId = attributePath.mAttributeId;

	ChipLogProgress(Zcl, "\n\nclusterId: >>>>>>> %" PRIu8, clusterId);
	ChipLogProgress(Zcl, "attributeId: >>>>>>> %" PRIu8, attributeId);

	if (clusterId == OnOff::Id && attributeId == OnOff::Attributes::OnOff::Id) {
		ChipLogProgress(Zcl, "Cluster OnOff: attribute OnOff set to %" PRIu8, *value);
		// GetAppTask().PostEvent(AppEvent(*value ? AppEvent::SensorActivate : AppEvent::SensorDeactivate, *value, true));
                GetAppTask().PostEvent(AppEvent(*value ? AppEvent::SensorActivate : AppEvent::SensorDeactivate));
	} else if (clusterId == TemperatureMeasurement::Id && attributeId == TemperatureMeasurement::Attributes::MeasuredValue::Id) {
		ChipLogProgress(Zcl, "Cluster TemperatureMeasurement: attribute MeasuredValue set to %" PRIu8, *value);
		GetAppTask().PostEvent(AppEvent(AppEvent::SensorMeasure));                
	}

}