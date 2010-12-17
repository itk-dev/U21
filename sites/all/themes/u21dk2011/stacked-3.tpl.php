  <?php if ($content['top']) { ?>
  <h2 class="sitemap-header"><?php print t('U21 Denmark 20011') ?> </h2>
  <div class="clear panel-col-top">
    <?php print $content['top']; ?>
  </div>
  <?php } ?>
  
  <?php if ($content['middle']) { ?>
  <h2 class="sitemap-header"><?php print t('Regional pages') ?> </h2>
  <div class="clear panel-col-middle">
    <?php print $content['middle']; ?>
  </div>
  <?php } ?>

  <?php if ($content['bottom']) { ?>
  <h2 class="sitemap-header"><?php print t('News and events') ?> </h2>
  <div class="clear panel-col-bottom">
    <?php print $content['bottom']; ?>
  </div>
  <?php } ?>
