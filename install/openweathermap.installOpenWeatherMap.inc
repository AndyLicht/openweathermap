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
    $instances['openweather_uuid'] = getInstance_Integer($t,'field_ow_uuid','UUID','openweathermap','node','UUID');
    $instances['openweather_station'] = getInstance_shortText($t,'field_ow_station','Stationsbezeichnung','openweathermap','node','Wetterstation');
    $instances['openweather_weatherupdate'] = getInstance_Integer($t,'field_ow_weatherupdate','letzter Wettereintrag','openweathermap','node','Wetterstation');
    $instances['openweather_szfreiername'] = getInstance_shortText($t,'field_ow_szfreiername','Maschinenname','openweathermap','node','Wetterstation Maschine');
    $instances['openweather_staat'] = getInstance_shortText($t,'field_ow_staat','Staat in dem sich die Wetterstation befindet','openweathermap','node','Staat');
    $instances['openweather_point'] = getInstance_Geometry($t, 'field_ow_point', 'Koordinate der Wetterstation', 'openweathermap', 'node', 'Koordinate der Wetterstation');
    $instances['openweather_area'] = getInstance_Geometry($t, 'field_ow_area', 'Koordinaten der Einzugsfläche', 'openweathermap', 'node', 'Einzugsgebiet der Wetterstation');
    return $instances;
}


