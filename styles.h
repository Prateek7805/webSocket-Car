const char css[] PROGMEM = R"=====(
*{
  box-sizing: border-box;
  margin: 0;
  padding: 0;
  outline: none;
}

html{
  -webkit-user-select: none; /* Safari */
  -moz-user-select: none; /* Firefox */
  -ms-user-select: none; /* IE10+/Edge */
  user-select: none; /* Standard */
}

body{
  font-family: monospace, Calibri , sans-serif;
  background-color: #1a1a2e;
}

.center{
  display: table;
  margin-left: auto;
  margin-right: auto;
}
.generalWhite{
  color: #fff;
}
.generalWidth{
  width: 80%;
}
.generalButton{
  background-color: #fff;
  padding:20px;
  margin: 10px;
  border: none;
  border-radius: 5px;
  transition-duration: 150ms;
  transition-property: transform;
  transition-timing-function: ease-in-out;
}

.generalButton:active{
  transform:scale(0.97);
}
.generalRange {
  -webkit-appearance: none;
  width: 90%;
  height: 10px;
  border-radius: 5px;
  background: #d3d3d3;
  outline: none;
  opacity: 0.7;
  -webkit-transition: .2s;
  transition: opacity .2s;
}

.generalRange:hover {
  opacity: 1;
}

.generalRange::-webkit-slider-thumb {
  -webkit-appearance: none;
  appearance: none;
  background-color: #a2f371;
  width: 20px;
  height: 20px;
  border-radius: 50%;
  cursor: pointer;
  border: none;
}

.generalRange::-moz-range-thumb {
  width: 20px;
  height: 20px;
  background-color: #a2f371;
  border-radius: 50%;
  cursor: pointer;
  border: none;
}

.container{
  width: 100%;
}
.header{
  margin-top: 10px;
 background-color: #03c4a1;
 border: none;
 border-radius: 4px;
}
.content{
  width : 80%;
}
.buttons{
  margin-top: 20px;
}


.range{
  margin-top: 20px;
  width: 45%;
}
#rangeVal{
  margin-left: 10px;
}


@media(max-width: 767px) and (min-width: 500px){
  .range{
    width: 60%;
  }
}

@media(max-width: 499px){
  .range{
    width: 80%;
  }
  .generalRange{
    width: 70%
  }
}


)=====";