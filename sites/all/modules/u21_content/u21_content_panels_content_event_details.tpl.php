<h2><?php print $title ?></h2>
<table>
  <tr>
    <td class="label"><?php print t('Date') ?>:</td>
    <td><?php print $date ?></td>
  </tr>
  <tr>
    <td class="label"><?php print t('Time') ?>:</td>
    <td><?php print $time_start ?> - <?php print $time_end ?></td>
  </tr>
  <tr>
    <td class="label"><?php print t('Price') ?>:</td>
    <td><?php print $price ?> Kr</td>
  </tr>
  <tr>
    <td class="label"><?php print t('Location') ?>:</td>
    <td>
      <b><?php print $address_name ?></b><br/>
      <?php print $address_street ?><br/>
      <?php print $address_city ?>
    </td>
  </tr>
</table>