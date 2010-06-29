<ul>
  <?php foreach ($terms as $term) { ?>
      <?php if ($term['count']) { ?>
        <li>
            <?php print $term['link'] ?>
            <span class="node-count"><?php print $term['count'] ?></span>
        </li>
      <?php } ?>
  <?php } ?>
</ul>
