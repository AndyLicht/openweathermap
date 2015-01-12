var $ = jQuery.noConflict();
$(document).ready(function($)
{
    $('#edit-id').attr('readonly', true);
    $('#edit-name').attr('readonly', true);
    $('#edit-staat').attr('readonly', true);
    $('#edit-x').attr('readonly', true);
    $('#edit-y').attr('readonly', true);
    $("#autoweather").attr('autocomplete','off');
    $('#autoweather').bind('input',function(e)
    {
        if(this.value.length >= 3 || e.keyCode == 13)
        {
            $('.autovorschlag-wetterstationen').html('');
            $.ajax(
            {
                url: 'http://api.openweathermap.org/data/2.5/find?callback=jQuery1910198190440190956_1405013843418&type=like',
                data:{q:this.value},
                dataType: 'jsonp',
                success: function (response)
                {
                    $('.autovorschlag-wetterstationen').html('');
                    $.each(response.list,function(i)
                    {
                        weatherstation = response.list[i];
                        name = weatherstation.name;
                        staat = weatherstation.sys.country;
                        id = weatherstation.id;
                        lon = weatherstation.coord.lon;
                        lat = weatherstation.coord.lat;
                        htmltext ="<div class='weatherstation-detail'><div class='id'>"+id+"</div><div class='name'>"+name+"</div><div class='staat'>"+staat+"</div><div class='lon'>"+lon.toFixed(2)+"</div><div class='lat'>"+lat.toFixed(2)+"</div></div>";
                        $('.autovorschlag-wetterstationen').append(htmltext);
                    });
                }
            });
        }
    });
    $('.autovorschlag-wetterstationen').on('click','.weatherstation-detail', function()
    {
        $('#edit-id').val($(this).children('.id').text());
        $('#edit-name').val($(this).children('.name').text());
        $('#edit-staat').val($(this).children('.staat').text());
        $('#edit-x').val($(this).children('.lon').text());
        $('#edit-y').val($(this).children('.lat').text());
    });
});