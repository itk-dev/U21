<?php
// $Id: semanticviews-view-fields.tpl.php,v 1.1.2.4 2010/02/20 14:43:06 bangpound Exp $
/**
 * @file semanticviews-view-fields.tpl.php
 * Default simple view template to display all the fields as a row. The template
 * outputs a full row by looping through the $fields array, printing the field's
 * HTML element (as configured in the UI) and the class attributes. If a label
 * is specified for the field, it is printed wrapped in a <label> element with
 * the same class attributes as the field's HTML element.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->element_type: The HTML element wrapping the field content and
 *     label.
 *   - $field->attributes: An array of attributes for the field wrapper.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle the
 *     recursion.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see template_preprocess_semanticviews_view_fields()
 * @ingroup views_templates
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 * brackets, the label element, slashes and whitespace.
 */
?>

<li class="player-marker" style="<?php if ($fields['field_profilepos_x_value']->content != "") : print 'left: '. $fields['field_profilepos_x_value']->content .';'; endif; if ($fields['field_profilepos_y_value']->content != "") : print 'top: '. $fields['field_profilepos_y_value']->content .';'; endif;  ?>;" tabindex="0">

<h3 class="player-shirtname"><?php print $fields['field_profile_shirtname_value']->content; ?></h3>
  
<div class="player-info">

<?php foreach ($fields as $id => $field): ?>

  <?php if ($id != 'field_profilepos_x_value' && $id != 'field_profilepos_y_value' && $id != 'field_profile_shirtname_value'): ?>
    <?php if ($field->element_type): ?>
      <<?php print $field->element_type; ?><?php print drupal_attributes($field->attributes); ?>>
    <?php endif; ?>
  
      <?php if ($field->label): ?>
  
        <?php if ($field->label_element_type): ?>
          <<?php print $field->label_element_type; ?><?php print drupal_attributes($field->label_attributes); ?>>
        <?php endif; ?>
  
            <?php print $field->label; ?>:
  
        <?php if ($field->label_element_type): ?>
          </<?php print $field->label_element_type; ?>>
        <?php endif; ?>
  
      <?php endif; ?>
  
        <?php print $field->content; ?>
  
    <?php if ($field->element_type): ?>
      </<?php print $field->element_type; ?>>
    <?php endif; ?>
  <?php endif; ?>

<?php endforeach; ?>
  <div class="player-info-inner"></div>
</div>
</li>