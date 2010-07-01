<?php if ($links) : ?>
  <h2><?php print $title ?></h2>
  <ul>
  <?php foreach ($links as $link) { ?>
    <li><?php print $link ?></li>
  <?php } ?>
  </ul>
<?php endif ?>