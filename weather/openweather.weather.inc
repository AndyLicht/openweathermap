<?php

class openweather_weather
{
    var $weatherofweatherstation = [];
    var $interpolierteswetter = [];
    var $from = NULL;
    var $to = NULL;
    var $weatherstation = NULL;
    var $weather = [];

    /*
     * Constructor, erzeugt alle Variablen und führt auch alle Funktionen aus
     */
    function openweather_weather($weatherstation, $from, $to)
    {
	$this->weatherstation = $weatherstation;
	$this->from = $from;
	$this->to = $to;
	$this->getweatherdatafromdatabase();
        $this->interpoliereweatherdata();
    }

    /*
     * Abfrage der entsprechenden Datenbanktablle nach sämtlichen Wetterdaten, eingeschränkt auf die bereits im Konstruktor angegebene Zeitspanne
     */
    function getweatherdatafromdatabase()
    {
	//select * from ow_example_2844588 where timestamp>'2014-12-20' and timestamp <'2014-12-28';
	$result = db_query("SELECT * from ".$this->weatherstation." where timestamp >'".$this->from."' and timestamp < '".$this->to."';" );
	foreach ($result as $entry)
	{
	    //Temperatur umwandeln in °C durch die Subtraktion von -273.5
            $values = new weatherentry($entry->timestamp, $entry->rain, $entry->temp-273.5, $entry->snow, $entry->humidity);
            array_push($this->weatherofweatherstation,$values);
	}
    }
    
    
    
    
    function interpoliereweatherdata()
    {
        $datum = [];
        $datumundzeit = [];
        foreach ($this->weatherofweatherstation as $wetter)
        {
            array_push($datum, substr($wetter->timestamp, 0, 10));
        }
        //die Stunden einfügen die ich möchte von 00:00 Uhr bis 23:00 Uhr
        foreach (array_unique($datum) as $day)
        {
            $i = 0;
            $weatherday = new weatherday($day);
            while ($i<24)
            { 
                if($i<10)
                {
                    array_push($datumundzeit,$day.' 0'.$i.':00:00+01');
                }
                else
                {
                    array_push($datumundzeit,$day.' '.$i.':00:00+01');
                }
                $i++;
            }
            $this->follower($datumundzeit,$weatherday);
            array_push($this->weather,$weatherday);
            $datumundzeit = [];
        }
    }
    
    function openweatherinterpol($datetime,$options,$weatherday)
    {
        $inttemp = NULL;
        $intrain = NULL;
        $intsnow = NULL;
        $inthumidity = NULL;
        if(is_null($options['groesser']) && !is_null($options['kleiner']))
        {
            $inttemp = $options['temp_min'];
            $intrain = $options['rain_min'];
            $intsnow = $options['snow_min'];
            $inthumidity = $options['humidity_min']; 
        }
        elseif(!is_null($options['groesser']) && is_null($options['kleiner']))
        {
            $inttemp = $options['temp_max'];
            $intrain = $options['rain_max'];
            $intsnow = $options['snow_max'];
            $inthumidity = $options['humidity_max']; 
        }
        else
        {
            $inttemp = $this->interpolierung($options['difference_min_null'],$options['difference_max_null'],$options['temp_min'],$options['temp_max']);
            $intrain = $this->interpolierung($options['difference_min_null'],$options['difference_max_null'],$options['rain_min'],$options['rain_max']);
            $intsnow = $this->interpolierung($options['difference_min_null'],$options['difference_max_null'],$options['rain_min'],$options['snow_max']);
            $inthumidity = $this->interpolierung($options['difference_min_null'],$options['difference_max_null'],$options['rain_min'],$options['humidity_max']);
        }
        $interpoliertesWetter = new weatherentry($datetime, $intrain, $inttemp, $intsnow, $inthumidity);
        //Weatherentry an weatherday anhängen
        $weatherday->addWeather($interpoliertesWetter);
    }
    
    
    
    function interpolierung($diffmin,$diffmax,$valuemin,$valuemax)
    {
        if(!is_null($valuemin) && !is_null($valuemax))
        { 
            if($diffmin<0)
            {
                $diffmin = $diffmin * -1;
            }
            if($diffmax<0)
            {
                $diffmax = $diffmax * -1;
            }
            $diff = $diffmin + $diffmax;
            $valuediff = $valuemax - $valuemin;
            $intervall = $valuediff / $diff;
            $value = $valuemin + ($diffmin*$intervall);
            return $value;
        }
        elseif (!is_null($valuemin) && is_null($valuemax))
        {
            $value = $valuemin;
            return ($value);
        }
        elseif(is_null($valuemin) && !is_null($valuemax))
        {
            $value = $valuemax;
            return $value;
        }
        else
        {
            return null;
        }
    }
    function follower($datumundzeit,$weatherday)
    {
        foreach($datumundzeit as $datetime)
        {
            $options['difference_min_null'] = NULL;
            $options['temp_min'] = NULL;
            $options['rain_min'] = NULL;
            $options['snow_min'] = NULL;
            $options['humidity_min'] = NULL;
            $options['difference_max_null'] = NULL;
            $options['temp_max'] = NULL;
            $options['rain_max'] = NULL;
            $options['snow_max'] = NULL;
            $options['humidity_max'] = NULL;
            $options['kleiner'] = NULL;
            $options['groesser'] = NULL;
            foreach ($this->weatherofweatherstation as $wetter)
            {  
               $difference = strtotime($datetime) - strtotime($wetter->timestamp);
               if ($difference > 0)
               {
                   if($difference < $options['difference_min_null'] || is_null($options['difference_min_null']))  //Überprüfen ob der Abstand kleiner als der Vorhandene ist
                   {
                       $options['kleiner'] = $wetter->timestamp;
                       $options['difference_min_null'] = $difference;
                       $options['temp_min'] = $wetter->temp;
                       $options['rain_min'] = $wetter->rain;
                       $options['snow_min'] = $wetter->snow;
                       $options['humidity_min'] = $wetter->humidity;
                   }
               }
               else
               {
                   if($difference > $options['difference_max_null'] || is_null($options['difference_max_null']))  //Überprüfen ob der Abstand kleiner als der Vorhandene ist
                   {
                       $options['groesser'] = $wetter->timestamp;
                       $options['difference_max_null'] = $difference;
                       $options['temp_max'] = $wetter->temp;
                       $options['rain_max'] = $wetter->rain;
                       $options['snow_max'] = $wetter->snow;
                       $options['humidity_max'] = $wetter->humidity;
                   }
               }     
            }
            $this->openweatherinterpol($datetime,$options,$weatherday);
        }
    }  
}

class weatherentry
{
    var $timestamp = null;
    var $temp = null;
    var $rain = null;
    var $snow = null;
    var $humidity = null;
    var $forecast = false;
    
    function weatherentry($timestamp,$rain,$temp,$snow,$humidity)
    {
        $this->timestamp =$timestamp;
        $this->temp = $temp;
        $this->snow = $snow;
        $this->rain = $rain;
        $this->humidity = $humidity;
    } 
}

class weatherday
{
    var $timestamp = null;
    var $datum = null;
    var $weather = [];
   
    
    function weatherday($day)
    {
        $this->timestamp = strtotime($day);
        $this->datum = $day;
    }
    
    function addWeather($wettereintrag)
    {
        array_push($this->weather,$wettereintrag);
    }
    
    function avValue($whichValue)
    {
        $average = null;
        $i = 0;
        foreach ($this->weather as $value)
        {
            $i++;
            $average = $average + $value->$whichValue;
        }
        return $average/$i;
    }
    
    function maxValue($whichValue)
    {
        $maximum = null;
        foreach ($this->weather as $value)
        {
            if($maximum <= $value->$whichValue)
            {
                $maximum = $value->$whichValue;
            }
        }
        return $maximum;
    }
    function minValue($whichValue)
    {
        $minimum = null;
        foreach ($this->weather as $value)
        {
            if($minimum >= $value->$whichValue || $minimum == null)
            {
                $minimum = $value->$whichValue;
            }
        }
        return $minimum;
    }
}