/***
 * This js files creates a tab based menu for player profiles.
 ***/
$(document).ready(function ()  {
  var info = $("div[id^=profile-tab]");

  // Insert tab menu
  var menu = $('<div id="tabs-profile-menu"></div>');
  $(info[0]).before(menu);

  // Build menu
  var ul = $('<ul></ul>');
  for (var i = 0; i < info.length; i++) {
    ul.append('<li><a href="#' + $(info[i]).attr('id') + '">' + $('h2',info[i]).text() + '</a></li>');
  }
  menu.append(ul);

  // Move content inside menu
  menu.append(info);

  // Enable menu tabs
  menu.tabs();
});