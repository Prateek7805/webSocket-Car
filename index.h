const char html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale = 1">
    <link rel="stylesheet" href="styles.css">
    <title>Socket car</title>
  </head>
  <body>
    <div class="container">
      <div class="header generalWidth center">
        <h1 class="center generalWhite">Socket Car</h1>
      </div>
      <div class="content center">
        <div class="buttons">
          <div class="row center">
            <button id="forward" class="generalButton">&#8593;</button>
          </div>
          <div class="row center">
            <button id="left" class="generalButton">&#8592;</button><button id="stop" class="generalButton">S</button><button id="right" class="generalButton">&#8594;</button>
          </div>
          <div class="row center">
            <button id="backward" class="generalButton">&#8595;</button>
          </div>
        </div>
        <div class="range center">
            <input type="range" id="range" class="generalRange" min="0" max="1023" value="0" step="1"><span class="generalWhite" id="rangeVal">0</span>
        </div>
      </div>
    </div>
    <script src="script.js"></script>
  </body>
</html>

)=====";