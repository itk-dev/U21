/**
* Extend a gmap.module map.
*/
Drupal.gmap.addHandler('gmap', function(elem) {
  var obj = this;

  /**
   * Init code for the map.
   * This seems to be the most reliable place for finding the actual map object
   * with gmap.module.
   */
  obj.bind('init',function() {
    var map = obj.map;

    // Load map markers. This could be moved to be triggered by some other event.
    $.getJSON("/u21_gmap/list", function(data) {
      $.each(data, function (key, item) {
        var marker;
        // Create this marker and add it to the map.
        marker = new GMarker(new GLatLng(item.latitude, item.longitude), {title:item.title});
        map.addOverlay(marker);
        // Add click event to the marker.
        GEvent.addListener(marker, 'click', function() {
          window.location.href = item.url;
        });
      });
    });
  });
});