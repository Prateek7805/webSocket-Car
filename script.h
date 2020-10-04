const char js[] PROGMEM = R"=====(
var Socket;
document.addEventListener('DOMContentLoaded', init, false);
function init(){
  Socket = new WebSocket('ws://'+window.location.hostname+':81/');
  Socket.onmessage = function(event){
    console.log(event.data);
  }
}

function _send(head, data){
  Socket.send(head+data);
}

function doc(id){
  return document.getElementById(id);
}

doc('forward').addEventListener('touchstart', buttonPress);
doc('backward').addEventListener('touchstart', buttonPress);
doc('left').addEventListener('touchstart', buttonPress);
doc('right').addEventListener('touchstart', buttonPress);
doc('stop').addEventListener('touchstart', buttonPress);

doc('forward').addEventListener('mousedown', buttonPress);
doc('backward').addEventListener('mousedown', buttonPress);
doc('left').addEventListener('mousedown', buttonPress);
doc('right').addEventListener('mousedown', buttonPress);
doc('stop').addEventListener('mousedown', buttonPress);

function buttonPress(){
  _send(this.id[0], 1);
}

doc('forward').addEventListener('touchend', buttonRelease);
doc('backward').addEventListener('touchend', buttonRelease);
doc('left').addEventListener('touchend', buttonRelease);
doc('right').addEventListener('touchend', buttonRelease);
doc('stop').addEventListener('touchend', buttonRelease);

doc('forward').addEventListener('mouseup', buttonRelease);
doc('backward').addEventListener('mouseup', buttonRelease);
doc('left').addEventListener('mouseup', buttonRelease);
doc('right').addEventListener('mouseup', buttonRelease);
doc('stop').addEventListener('mouseup', buttonRelease);
document.addEventListener('mouseup', function(){
  _send('s', 0);
});

function buttonRelease(){
  _send(this.id[0], 0);
}

doc('range').addEventListener('input', function(){
  doc('rangeVal').innerHTML = this.value;
  _send('v', this.value);
});

)=====";