  <?php if ($content['top']) { ?>
  <div class="clear panel-col-top">
    <?php print $content['top']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['left']) { ?>
    <div class="grid-2 alpha panel-col-left">
      <?php print $content['left']; ?>
    </div>
  <?php } ?>

  <?php if ($content['center']) { ?>
  <div class="<?php if (!$content['left']) { ?>prefix-2 alpha <?php } ?><?php if (!$content['right']) { ?><?php } ?>grid-6 panel-col-center">
    <?php print $content['center']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['right']) { ?>
  <div class="grid-4 omega panel-col-right">
    <?php print $content['right']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['lower_left']) { ?>
  <div class="<?php if (!$content['lower_right']) { ?>suffix-4 omega <?php } ?>grid-8 alpha panel-col-lowleft">
    <?php print $content['lower_left']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['lower_right']) { ?>
  <div class="<?php if (!$content['lower_left']) { ?>prefix-8 alpha <?php } ?>grid-4 omega panel-col-lowright">
    <?php print $content['lower_left']; ?>
  </div>
  <?php } ?>  


<?php if ($content['VAR']) { ?>  <?php } ?>