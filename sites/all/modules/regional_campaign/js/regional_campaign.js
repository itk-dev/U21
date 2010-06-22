
Drupal.behaviors.bannerBehavior = function () {
  $(".regional-campaign-random a[rel='external']").click(function() {
    window.open(this.href);
    return false;
  })
};

