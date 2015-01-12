<?php
//Instance für ein einfaches Textfeld
function getInstance_shortText($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance= array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'text_textfield',
       ),
       'display' => array(
           'default' => array(
               'label' => 'above',
               'type' => 'text',
           ),
       ),
       'description' => $description,
   );
   return $instance;
}
//Instance für ein langes Textfeld
function getInstance_longText($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance= array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'text_textarea',
       ),
       'display' => array(
           'default' => array(
               'label' => 'above',
               'type' => 'text_long',
           ),
       ),
       'description' => $description,
   );
   return $instance;
}
 
 
//Instance für eine einfache FieldCollection
function getInstance_FieldCollection($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance = array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'field_collection_embed',
       ),
       'display' => array(
           'default' => array(
               'label' => 'above',
               'type' => 'field_collection_items',
           ),
       ),
       'description' => $description,
   );
return $instance;
}
//Instance für ein Taxonomyfeld
function getInstance_TermRef($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance = array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'options_select',
       ),
       'display' => array(
           'default' => array('type' => 'hidden'),
           'teaser' => array('type' => 'hidden')
       ),
       'description' => $description,
   );
return $instance;
}
 
 
//Instance für ein einfaches Booleanfeld
function getInstance_Boolean($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance = array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'weight' => '12',
           'type' => 'options_onoff', //muss noch dynamisch ueber die Funktion abgebildet werden
           'module' => 'options',
           'active' => 1,
       ),
       'display' => array(
           'default' => array('type' => 'above'),
       ),
       'description' => $description,
   );
return $instance;
}
 
//Instance für ein einfaches Integerfeld
function getInstance_Integer($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance = array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'number',
       ),
       'display' => array(
           'default' => array('type' => 'above'),
       ),
       'description' => $description,
   );
return $instance;
}
 
//Instance für ein einfaches Integerfeld
function getInstance_Decimal($t,$name,$label,$bundle,$entity_type,$description)
{
   $instance = array(
       'field_name' => $name,
       'label'       => $t($label),
       'bundle' => $bundle,
       'entity_type' => $entity_type,
       'widget'      => array(
           'type'    => 'number',
       ),
       'display' => array(
           'default' => array('type' => 'above'),
       ),
       'description' => $description,
   );
return $instance;
}
 
//Image
function getInstance_Image($t,$name,$label,$bundle,$entity_type,$description)
{
        $instance = array(
                'field_name' => $name,
                'label'       => $t($label),
                'bundle' => $bundle,
                'entity_type' => $entity_type,
                'widget'      => array(
                        'type'    => 'image_image',
                ),
                'display' => array(
                        'default' => array('type' => 'above'),
                ),
 
                'description' => $description,
        );
return $instance;
}
 
//GIS
function getInstance_Geometry($t,$name,$label,$bundle,$entity_type,$description)
{
    $instance = array(
        'label' => $t($label),
        'module' => 'geofield',
        'weight' => 1,
        'required' => 0,
        'description' => $description,
        'default_value' => NULL,
        'field_name' => $name,
        'entity_type' => $entity_type,
        'bundle' => $bundle,
        'deleted' => '0',
        'widget' => array(
            'weight' => '-3',
            'type' => 'geofield_wkt',
            'module' => 'geofield',
            'active' => 1,
            'settings' => array(
                'html5_geolocation' => 0,
            ),
        ),
        'settings' => array(
            'user_register_form' => FALSE,
        ),
        'display' => array(
            'default' => array(
                'label' => 'above',
                'type' => 'geofield_wkt',
                'settings' => array(
                    'data' => 'full',
                ),
            ),
            'teaser' => array(
                'type' => 'hidden',
                'label' => 'above',
                'settings' => array(),
                'weight' => 0,
            ),
        ),        
    );
    return $instance;
}                                                                      