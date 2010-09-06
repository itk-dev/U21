// Open selected external links in a new window
function openExternal() {
  $("a[rel='external']").click(function(){
    window.open(this.href);
    return false;
  });
}

function runOnStartup () {
  openExternal();
}


// Run startup functions on dom ready
$(document).ready(runOnStartup);
