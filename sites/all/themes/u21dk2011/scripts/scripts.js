// Open selected external links in a new window
function openExternal() {
  $("a[rel='external']").click(function(){
    window.open(this.href);
    return false;
  });
}

// Behavior for playing field lineups
function lineupSetEvents() {
  $(".player-marker")
    .live('click', lineupShowBubble);
  $(".player-info .close-button")
    .live('click', lineupHideBubble);
  $(".player-info")
    .append('<a href="#" class="close-button">Luk</a>');
}

function lineupShowBubble() {
  if (!$(this).hasClass('active-bubble')) {
    lineupHideBubble();
    $(this).children('.player-info')
      .fadeIn('fast')
      .end()
      .addClass('active-bubble');
  } else {
    lineupHideBubble();
  }
}

function lineupHideBubble() {
  $(".player-marker").children('.player-info')
    .hide()
    .end()
    .removeClass('active-bubble');
    return false;
}

function runOnStartup () {
  openExternal();
  lineupSetEvents();
}


// Run startup functions on dom ready
$(document).ready(runOnStartup);
