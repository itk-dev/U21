// $Id: homebox.js,v 1.1.2.2 2010/04/30 09:13:31 jchatard Exp $
Drupal.homebox = {};
Drupal.behaviors.homebox = function(context) {
  $homebox = $('#homebox:not(.homebox-processed)', context).addClass('homebox-processed');
  
  if ($homebox.length > 0) {
    // Find all columns
    $columns = $homebox.find('>div.homebox-column');
    
    // Equilize columns height
    $columns = Drupal.homebox.equalizeColumnsHeights($columns);
    //Drupal.addPlaceholders($columns);
    
    // Make columns sortable
    $columns.sortable({
      items: '.homebox-portlet.homebox-draggable',
      handle: '.portlet-header',
      connectWith: $columns,
      revert: true,
      placeholder: 'homebox-placeholder',
      forcePlaceholderSize: true,
      stop: function() {
        Drupal.homebox.saveBoxesOrder($columns);
      }
    });
    // Add tools links
    $boxes = $homebox.find('.homebox-portlet');
    $boxes.find('.portlet-config').each(function() {
      if (jQuery.trim($(this).html()) != '') {
        $(this).prev('.portlet-header').prepend('<span class="portlet-icon portlet-settings"></span>').end();
      };
    });
    $boxes.find('.portlet-header').prepend('<span class="portlet-icon portlet-minus"></span>')
        .prepend('<span class="portlet-icon portlet-close"></span>')
        .end();
    
    // Attach click event on minus
    $boxes.find('.portlet-header .portlet-minus').click(function() {
      $(this).toggleClass("portlet-minus");
      $(this).toggleClass("portlet-plus");
      $(this).parents(".homebox-portlet:first").find(".portlet-content").toggle();
      boxId = $(this).parents(".homebox-portlet:first").find(".portlet-content input:hidden.homebox").val();
      pid = $(this).parents(".homebox-portlet:first").find(".portlet-content input:hidden.pid").val();
      isOpen = $(this).parents(".homebox-portlet:first").find(".portlet-content").is(':visible');
      Drupal.homebox.saveOpenState(boxId, pid, isOpen);
    });
    // Attach click event on minus
    $boxes.find('.portlet-header .portlet-minus').each(function() {
      if (!$(this).parents(".homebox-portlet:first").find(".portlet-content").is(':visible')) {
        $(this).toggleClass("portlet-minus");
        $(this).toggleClass("portlet-plus");
      };
    });
    // Attach click event on settings icon
    $boxes.find('.portlet-header .portlet-settings').click(function() {
      $(this).parents(".homebox-portlet:first").find(".portlet-config").toggle();
      Drupal.homebox.equalizeColumnsHeights($columns);
    });
    // Attach click event on close
    $boxes.find('.portlet-header .portlet-close').click(function() {
      $(this).parents(".homebox-portlet:first").hide();
      // Uncheck input settings
      dom_id = $(this).parents(".homebox-portlet:first").attr('id');
      $('#homebox_toggle_' + dom_id).attr('checked', false);
      Drupal.homebox.saveBoxesOrder();
    });
    // Add click behaviour to checkboxes that enable/disable blocks
    $togglers = $homebox.find('#homebox-settings input.homebox_toggle_box');
    $togglers.click(function() {
      if ($(this).attr('checked')) {
        el_id = $(this).attr('id').replace('homebox_toggle_', '');
        $('#' + el_id).show();
      }else{
        el_id = $(this).attr('id').replace('homebox_toggle_', '');
        $('#' + el_id).hide();
      };
      Drupal.homebox.saveBoxesOrder();
    });
    // Add click behaviour to color buttons
    $boxes.find('.homebox-color-selector').click(function() {
      color = $(this).css('background-color');
      classes = $(this).parents(".homebox-portlet:first").attr('class').split(" ");
      jQuery.each(classes, function(key, value) {
        if (value.indexOf('homebox-color-') == 0) {
          classes[key] = "";
        };
      });
      classes = classes.join(" ");
      $(this).parents(".homebox-portlet:first").attr('class', classes);
      $(this).parents(".homebox-portlet:first").addClass("homebox-color-" + Drupal.homebox.convertRgbToHex(color).replace("#", ''));
      boxId = $(this).parents(".homebox-portlet:first").find(".portlet-content input:hidden.homebox").val();
      pid = $(this).parents(".homebox-portlet:first").find(".portlet-content input:hidden.pid").val();      
      Drupal.homebox.saveBoxesColor(boxId, pid, color);
    });
    // Add content link
    $('#homebox-add').click(function() {
      // View CSS file for more details on this
      $('#homebox-settings').toggleClass("homebox-settings-hidden");
      $('#homebox-settings').toggleClass("homebox-settings-show");
      // Prevent click event propagation
      return false;
    });
    
    $homebox.ajaxStop(function(){
      Drupal.homebox.equalizeColumnsHeights($columns);
    });
  }
};

Drupal.homebox.equalizeColumnsHeights = function(columns) {
  maxHeight = 0;
  $columns.each(function() {
    $(this).height('auto');
    currentHeight = $(this).height();
    if (maxHeight < currentHeight) {
      maxHeight = currentHeight;
    };
  }).each(function() {
    $(this).height(maxHeight);
  });
  return $columns;
};

Drupal.homebox.saveBoxesOrder = function() {
  var newOrder = new String();
  $columns = Drupal.homebox.equalizeColumnsHeights($columns);
  $columns.each(function(colIndex) {
    var colIndex = colIndex + 1;
    $(this).find('>.homebox-portlet').each(function(boxIndex) {
      visible = 0;
      if ($(this).is(':visible')) {
        visible = 1;
      };
      newOrder += colIndex + ":" + $(this).find('input:hidden.homebox').val() + ":" + visible + " ";
      pid = $(this).find('input:hidden.pid').val();
    });
  });
  
  $.ajax({
    url: Drupal.settings.basePath + '?q=homebox/save',
    type: "POST",
    dataType: "json",
    data: {order: newOrder, pid: pid},
    error: function() {
      console.log(Drupal.t("An error occured while trying to save you settings."))
    }
  });
}

Drupal.homebox.saveBoxesColor = function(boxId, pid, color) {
  color = Drupal.homebox.convertRgbToHex(color);
  $.ajax({
    url: Drupal.settings.basePath + '?q=homebox/save-color',
    type: "POST",
    dataType: "json",
    data: {box: boxId, pid: pid, color: color},
    error: function() {
      console.log(Drupal.t("An error occured while trying to save you settings."))
    }
  });
};

Drupal.homebox.saveOpenState = function(boxId, pid, isOpen) {
  $columns = Drupal.homebox.equalizeColumnsHeights($columns);
  if (isOpen == true) {
    isOpen = 1;
  }else{
    isOpen = 0;
  }
  $.ajax({
    url: Drupal.settings.basePath + '?q=homebox/save-open',
    type: "POST",
    dataType: "json",
    data: {box: boxId, pid: pid, open: isOpen},
    error: function() {
      console.log(Drupal.t("An error occured while trying to save you settings."))
    }
  });
};

Drupal.homebox.convertRgbToHex = function(rgb) {
  if (!jQuery.browser.msie) {
    // Script taken from
    // http://stackoverflow.com/questions/638948/background-color-hex-to-js-variable-jquery
    var parts = rgb.match(/^rgb\((\d+),\s*(\d+),\s*(\d+)\)$/);
    // parts now should be ["rgb(0, 70, 255", "0", "70", "255"]
    delete (parts[0]);
    for (var i = 1; i <= 3; ++i) {
      parts[i] = parseInt(parts[i]).toString(16);
      if (parts[i].length == 1) parts[i] = '0' + parts[i];
    }
    return "#" + parts.join(''); // "0070ff"
  } else {
    return rgb;
  };
};