<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body class="<?php print $body_classes; ?> show-grid">
  
  <div id="wrapper" class="container-12">
  
    <div id="header">
      
      <div id="branding" class="grid-12">
        <?php print $site_logo; ?>
        <?php if ($site_slogan): ?>
        <div id="site-slogan" class=""><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
      
      <?php if ($region_main_menu): ?>
        <div id="region-main-menu" class="grid-8">
        <?php print $region_main_menu; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_city_menu): ?>
        <div id="region-city-menu" class="grid-4">
        <?php print $region_city_menu; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_secondary_menu): ?>
        <div id="region-secondary-menu" class="grid-12">
        <?php print $region_secondary_menu; ?>
        </div>
      <?php endif; ?>    
    
    </div><!-- /header -->

    <?php print $breadcrumb; ?>

    <?php if ($region_top): ?>
      <div id="region-top" class="region grid-12">
      <?php print $region_top; ?>
      </div>
    <?php endif; ?>
       
    <div id="content">
      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php if ($tabs): ?>
        <div class="tabs"><?php print $tabs; ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <?php print $help; ?>
      <div id="main-content" class="region clear-block">
        <?php print $content; ?>
      </div>
    </div><!-- /content -->

    <div id="secondary-content">
      <?php if ($region_middle): ?>
        <div id="region-middle" class="region grid-12">
        <?php print $region_middle; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_middle_left): ?>
        <div id="region-middle-left" class="region grid-4">
        <?php print $region_middle_left; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_middle_center): ?>
        <div id="region-middle-center" class="region grid-4">
        <?php print $region_middle_center; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_middle_right): ?>
        <div id="region-middle-right" class="region grid-4">
        <?php print $region_middle_right; ?>
        </div>
      <?php endif; ?>
      <?php if ($region_bottom): ?>
        <div id="region-bottom" class="region grid-12">
        <?php print $region_bottom; ?>
        </div>
      <?php endif; ?>
    
    </div><!-- /Secondary content -->
  
    <?php if ($footer_1 || $footer_2 || $footer_3 || $footer_4): ?>
    <ul id="footer" class="grid-12">
        <?php if ($footer_1): ?>        
        <li class="region grid-3">
          <?php print $footer_1; ?>
        </li>
        <?php endif; ?>
        <?php if ($footer_2): ?>        
        <li class="region grid-3">
          <?php print $footer_2; ?>
        </li>
        <?php endif; ?>
        <?php if ($footer_3): ?>        
        <li class="region grid-3">
          <?php print $footer_3; ?>
        </li>
        <?php endif; ?>
        <?php if ($footer_4): ?>        
        <li class="region grid-3">
          <?php print $footer_4; ?>
        </li>
        <?php endif; ?>
    </ul><!-- /footer -->
    <?php endif; ?>

  </div><!-- /wrapper -->
  <?php print $closure; ?>
</body>
</html>
