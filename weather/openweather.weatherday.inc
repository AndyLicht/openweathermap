<?php

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