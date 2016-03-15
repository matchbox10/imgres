<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function imgres_setup_form($form, &$form_state) {

    $form['flush'] = array(
        '#type' => 'checkbox', //you can find a list of available types in the form api
        '#title' => t('On each Cron run flush all <b>Imgress</b> image styles'),
        '#description' => l('Manually flush all images', '/imgres/delete', array('query' => array('destination' => $_GET['q']))),
        '#default_value' => variable_get('imgres_cron_flush', 0),
         '#states' => array(
            // Hide the settings when the cancel notify checkbox is disabled.
            'visible' => array(':input[name="delete"]' => array('checked' => FALSE),
            ),
        ),
    );
    $form['delete'] = array(
        '#type' => 'checkbox', //you can find a list of available types in the form api
        '#title' => t('On each Cron run delete all <b>Imgress</b> image styles'),
        '#description' => l('Manually delete all', '/imgres/delete', array('query' => array('destination' => $_GET['q']))),
        '#default_value' => variable_get('imgres_cron_delete', 0),
         '#states' => array(
            // Hide the settings when the cancel notify checkbox is disabled.
            'visible' => array(':input[name="flush"]' => array('checked' => FALSE),
            ), 
        ),
    );

    $form['submit_button'] = array(
        '#type' => 'submit',
        '#value' => t('Update'),
    );

    return $form;
}

function imgres_setup_form_validate($form, &$form_state) {
}

#complete form submition
function imgres_setup_form_submit($form, &$form_state) {

    variable_set('imgres_cron_flush', $form_state['values']['flush']);
    variable_set('imgres_cron_delete', $form_state['values']['delete']);
    drupal_set_message(t('Your configuration has been saved.'));
}
