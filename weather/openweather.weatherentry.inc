<?php

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