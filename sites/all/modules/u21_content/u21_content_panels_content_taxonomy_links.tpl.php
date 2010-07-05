<ul>
  <li>
    <?php print $terms['all']['link'] ?>
  </li>
  <?php foreach ($terms as $key => $term) { ?>
      <?php if ($key == 'all') { continue; }?>
      <?php //if ($term['count']) : ?>
        <li>
            <?php print $term['link'] ?>
            <span class="node-count">(<?php print $term['count'] ?>)</span>
        </li>
      <?php //endif ?>
  <?php } ?>
</ul>
