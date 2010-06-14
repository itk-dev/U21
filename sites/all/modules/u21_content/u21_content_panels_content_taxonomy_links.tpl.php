<h2><?php print $title ?></h2>
<ul>
  <?php foreach ($terms as $term) { ?>
        <li>
            <?php print $term['link'] ?>
            <span class="node-count"><?php print $term['count'] ?></span>
        </li>
  <?php } ?>
</ul>
