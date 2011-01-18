$(document).ready(function() {
  var context = $('#webform-client-form-919');
  var input = context.find('input[type=text]');
  
  // Convert all input elements with value into p tags
  for (var i = 0; i < input.length; i++) {
    var element = $(input[i]);
    if (element.val()) {
      element.hide();
      element.parent().append('<p>'+element.val()+' <a class="webform-edit-link" href="">'+Drupal.t('Edit')+'</a></p>').show();
    }
  }

  // Attach edit like click
  $('.webform-edit-link').click(function() {
    $(this).parent().siblings('input').show();
    $(this).parent().remove();
    return false;
  });
});