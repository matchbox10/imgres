# Imgres
Drupal Module to easily create and apply image styles 

Create Sizes:

/imgres/[width]/[height]


Parameters:

When using nid 
n = nid with the image you wish to use
c = when multiple images have been uploaded, select the image number you wish to use. Default is 0
field = The name of the field containing the image in the node 'field_image' is default. This is set in manage fields.


l = uri of the image you wish to use
e = Type of effect you would like to use, default is image_scale_and_crop. List of effects can be found: https://api.drupal.org/api/drupal/modules!image!image.effects.inc/7

Example URLs:

www.yoursite.com/imgres/300/200?n=1
www.yoursite.com/imgres/1300/800?n=53&c=2
www.yoursite.com/imgres/680/340?n=52&c=1&field=field_my_custom_image
www.yoursite.com/imgres/360/240?l=public://images/my-custom-image.png
www.yoursite.com/imgres/300/200?n=1&e=image_resize