
Drupal.behaviors.bannerBehavior = function () {
  $(".random-campaign a[rel='external']").click(function() {
    window.open(this.href);
    return false;
  })
};

