<?php
//Text
function getField_shortText($t,$name,$label,$count,$size)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type'        => 'text',
        'settings' => array(
            'max_length' => $size,
        ),
    );
    return $field;
}
 
function getField_longText($t,$name,$label,$count)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type'        => 'text_long',
);
    return $field;
}
 
//FieldCollection
function getField_FieldCollection($t,$name,$label,$count)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'field_collection',
    );
    return $field;
}
 
//Terms
function getField_TermRef($t,$name,$label,$count,$vocabular)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'taxonomy_term_reference',
        'settings' => array(
            'allowed_values' => array(
                array(
                    'vocabulary' => $vocabular,
                    'parent' => 0
                )
            )
        )
    );
    return $field;
}
 
//Boolean
function getField_Boolean($t,$name,$label,$count,$false,$true)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'list_boolean',
        'settings' => array(
            'allowed_values' => array(
                0 => $false,
                1 => $true,
            ),
            'allowed_values_function' => '',
        ),
    );
    return $field;
}
//Zahlenformate
//Integer
function getField_Integer($t,$name,$label,$count)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'number_integer',
    );
    return $field;
}
//Decimal
function getField_Decimal($t,$name,$label,$count,$precision,$scale)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'number_decimal',
        'settings' => array(
            'precision' => $precision,
            'scale' => $scale,
            'decimal_separator' => '.',
        ),
    );
    return $field;
}
 
//Image
function getField_Image($t,$name,$label,$count)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'cardinality' => $count,
        'type' => 'image',
        'setting' => array(
            'uri_scheme' => 'public',
            'default_image' => 0,
        ),
    );
    return $field;
}
 
//GIS Fields

function getField_Geometry($t,$name,$label,$count)
{
    $field = array(
        'field_name' => $name,
        'label' => $t($label),
        'type' => 'geofield',
        'module' => 'geofield',
        'active' => '1',
        'locked' => '0',
        'cardinality' => $count,
        'deleted' => '0',
        'columns' => array(
            'geom' => array(
                'type' => 'blob',
                'size' => 'big',
                'not null' => FALSE,
            ),
            'geo_type' => array(
                'type' => 'varchar',
                'default' => '',
                'length' => 64,
            ),
            'lat' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'lon' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'left' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'top' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'right' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'bottom' => array(
                'type' => 'numeric',
                'precision' => 18,
                'scale' => 12,
                'not null' => FALSE,
            ),
            'geohash' => array(
                'type' => 'varchar',
                'length' => 16,
                'not null' => FALSE,
            ),
        ),
        $name => array(
            'translatable' => '0',
            'entity_types' => array(),
            'settings' => array(
                'backend' => 'default',
                'srid' => '4326',
            ),
            'storage' => array(
                'type' => 'field_sql_storage',
                'settings' => array(),
                'module' => 'field_sql_storage',
                'active' => '1',
                'details' => array(
                    'sql' => array(
                        'FIELD_LOAD_CURRENT' => array(
                            'field_data_'.$name => array(
                                'geom' => $name.'_geom',
                                'geo_type' => $name.'_geo_type',
                                'lat' => $name.'_lat',
                                'lon' => $name.'_lon',
                                'left' => $name.'_left',
                                'top' => $name.'_top',
                                'right' => $name.'_right',
                                'bottom' => $name.'_bottom',
                                'geohash' => $name.'_geohash',
                            ),
                        ),
                        'FIELD_LOAD_REVISION' => array(
                            'field_revision_'.$name => array(
                                'geom' => $name.'_geom',
                                'geo_type' => $name.'_geo_type',
                                'lat' => $name.'_lat',
                                'lon' => $name.'_lon',
                                'left' => $name.'_left',
                                'top' => $name.'_top',
                                'right' => $name.'_right',
                                'bottom' => $name.'_bottom',
                                'geohash' => $name.'_geohash',
                            ),
                        ),
                    ),
                ),
            ),
        'foreign keys' => array(),
            'indexes' => array(
                'lat' => array(
                    0 => 'lat',
                ),
                'lon' => array(
                    0 => 'lon',
                ),
                'top' => array(
                    0 => 'top',
                ),
                'bottom' => array(
                    0 => 'bottom',
                ),
                'left' => array(
                    0 => 'left',
                ),
                'right' => array(
                    0 => 'right',
                ),
                'geohash' => array(
                    0 => 'geohash',
                ),
                'centroid' => array(
                    0 => 'lat',
                    1 => 'lon',
                ),
                'bbox' => array(
                    0 => 'top',
                    1 => 'bottom',
                    2 => 'left',
                    3 => 'right',
                ),
            ),
        ),
    );
    return $field;
}


