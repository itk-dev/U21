  <?php if ($content['top']) { ?>
  <div class="clear panel-col-top">
    <?php print $content['top']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['left']) { ?>
    <div class="grid-8 alpha panel-col-left">
      <?php print $content['left']; ?>
    </div>
  <?php } ?>
  
  <?php if ($content['right']) { ?>
  <div class="grid-4 omega panel-col-right">
    <?php print $content['right']; ?>
  </div>
  <?php } ?>


