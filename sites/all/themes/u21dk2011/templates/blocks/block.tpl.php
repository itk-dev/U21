<?php
// $Id$
/**
 * @file
 * block.tpl
 */

/*
ad a class="" if we have anything in the $classes var
this is so we can have a cleaner output - no reason to have an empty <div class="" id="">
 */
if ($classes) {
  $inner_classes = ' class="'. $classes .'-content"';
  $classes = ' class="' . $classes . '"';
}

if ($id_block) {
  $id_block = ' id="' . $id_block . '"';
}
?>

<div<?php print $id_block . $classes; ?>>
<?php if ($block->subject): ?>
  <h2><?php print $block->subject; ?></h2>
<?php endif; ?>
  <div<?php print $id_block . $inner_classes; ?>>
    <?php print $block->content; ?>
    <?php  print $edit_links; ?>
  </div>
</div>