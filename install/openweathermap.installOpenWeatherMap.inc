<?php

function install_ow_station()
{
    foreach (_ow_station_installed_instances() as $instance)
    {
        field_create_instance($instance);
    }
}


function _ow_station_installed_instances()
{
    $t = get_t();
    $instances = array();
    $instances['openweather_uuid'] = installHelper_getInstance_Integer($t,'field_ow_uuid','UUID','openweathermap','node','UUID');
    $instances['openweather_station'] = installHelper_getInstance_shortText($t,'field_ow_station','Stationsbezeichnung','openweathermap','node','Wetterstation');
    $instances['openweather_weatherupdate'] = installHelper_getInstance_Integer($t,'field_ow_weatherupdate','letzter Wettereintrag','openweathermap','node','Wetterstation');
    $instances['openweather_szfreiername'] = installHelper_getInstance_shortText($t,'field_ow_szfreiername','Maschinenname','openweathermap','node','Wetterstation Maschine');
    $instances['openweather_staat'] = installHelper_getInstance_shortText($t,'field_ow_staat','Staat in dem sich die Wetterstation befindet','openweathermap','node','Staat');
    $instances['openweather_point'] = installHelper_getInstance_Geometry($t, 'field_ow_point', 'Koordinate der Wetterstation', 'openweathermap', 'node', 'Koordinate der Wetterstation');
    $instances['openweather_area'] = installHelper_getInstance_Geometry($t, 'field_ow_area', 'Koordinaten der Einzugsfläche', 'openweathermap', 'node', 'Einzugsgebiet der Wetterstation');
    return $instances;
}


