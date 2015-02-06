<?php
function _create_fields()
{
    $t = get_t();
    $fields = array();
    $fields['openweather_uuid'] = installHelper_getField_Integer($t,'field_ow_uuid','UUID',1);
    $fields['openweather_station'] = installHelper_getField_shortText($t,'field_ow_station','Wetterstation',1,255);
    $fields['openweather_weatherupdate'] = installHelper_getField_Integer($t,'field_ow_weatherupdate','letzter Wettereintrag',1);
    $fields['openweather_szfreiername'] = installHelper_getField_shortText($t,'field_ow_szfreiername','Wetterstation Machine',1,255);
    $fields['openweather_staat'] = installHelper_getField_shortText($t,'field_ow_staat','Staat',1,255);
    $fields['openweather_area'] = installHelper_getField_Geometry($t, 'field_ow_area', 'Flächen Koordinaten', 1);
    $fields['openweather_point'] = installHelper_getField_Geometry($t, 'field_ow_point', 'Punkt Koordinaten', 1);
    return $fields;
 }

function installFields()
{
    foreach (_create_fields() as $field)
    {
        field_create_field($field);
    }
}
