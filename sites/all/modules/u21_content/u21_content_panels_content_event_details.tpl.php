<table>
  <tr>
    <td class="label"><?php print t('Date') ?>:</td>
    <td><?php print $date ?></td>
  </tr>
  <tr>
    <?php if ($time_start != '00:00') { ?>
    <td class="label"><?php print t('Time') ?>:</td>
    <td><?php print $time_start ?> - <?php print $time_end ?></td>
    <?php } ?>
  </tr>
  <tr>
    <td class="label"><?php print t('Price') ?>:</td>
    <td><?php print $price ?></td>
  </tr>
  <tr>
    <td class="label"><?php print t('Event location') ?>:</td>
    <td>
      <b><?php print $address_name ?></b><br/>
      <?php print $address_street ?><br/>
      <?php print $address_city ?>
    </td>
  </tr>
</table>
