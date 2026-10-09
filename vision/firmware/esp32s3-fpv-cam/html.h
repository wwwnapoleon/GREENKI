// html.h — HTML + CSS
#pragma once
#include <Arduino.h>

const char INDEX_HTML[] PROGMEM = R"CAMHTML(<!DOCTYPE html>
<html lang="ru">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>ESP32-S3 FPV</title>
<style>
  * { box-sizing: border-box; margin: 0; padding: 0; }
  html, body { height: 100%; }
  body { background: rgb(17,17,17); color: rgb(238,238,238);
         font-family: -apple-system, Roboto, sans-serif;
         display: flex; flex-direction: column; gap: 12px;
         padding: 12px; min-height: 100vh; }

  header { width: 100%; display: flex;
           justify-content: space-between; align-items: center;
           background: rgb(28,28,28); padding: 10px 14px;
           border-radius: 10px; font-size: 14px; flex: 0 0 auto; }
  header .brand { font-weight: 600; color: rgb(68,170,255); }
  header .rssi  { color: rgb(170,170,170); font-size: 13px; }

  /* ===== Главный блок: слева видео, справа серво ===== */
  .main {
    flex: 1 1 auto;
    display: grid;
    grid-template-columns: 2fr 1fr;    /* видео 2 части, серво 1 часть */
    gap: 12px;
    min-height: 0;
  }

  /* Видео-панель */
  .video-panel {
    background: rgb(28,28,28);
    border-radius: 12px;
    padding: 12px;
    display: flex; flex-direction: column; gap: 10px;
    min-height: 0;
  }
  .video-title { font-size: 13px; color: rgb(68,170,255);
                 font-weight: 600; }
  .video-wrap {
    flex: 1 1 auto; min-height: 0;
    background: black; border-radius: 10px;
    overflow: hidden;
    display: flex; align-items: center; justify-content: center;
  }
  .video-wrap img { width: 100%; height: 100%; object-fit: contain; }
  .video-status { display: flex; gap: 16px; font-size: 13px;
                  color: rgb(170,170,170); }
  .video-status .val { color: rgb(68,170,255); font-weight: 600; }

  /* Серво-панель */
  .servo-panel {
    background: rgb(28,28,28);
    border-radius: 12px;
    padding: 16px;
    display: flex; flex-direction: column;
    align-items: center; gap: 14px;
    min-height: 0;
    overflow-y: auto;
  }
  .servo-title { font-size: 13px; color: rgb(68,170,255);
                 font-weight: 600; text-align: center; }
  .servo-angle-big { font-size: 40px; font-weight: 800;
                     font-family: monospace; color: rgb(68,170,255);
                     line-height: 1; }

  .joystick { display: grid;
              grid-template-columns: 64px 64px 64px;
              grid-template-rows:    64px 64px 64px;
              gap: 6px; }
  .joy-btn { width: 64px; height: 64px;
             background: rgb(42,42,42);
             border: 2px solid rgb(68,68,68);
             color: rgb(238,238,238);
             border-radius: 12px; font-size: 24px; font-weight: 700;
             cursor: pointer;
             display: flex; align-items: center; justify-content: center;
             transition: background 0.1s, border-color 0.1s, transform 0.05s;
             user-select: none; -webkit-user-select: none;
             font-family: inherit;
             touch-action: manipulation; }
  .joy-btn:hover { background: rgb(58,58,58); border-color: rgb(68,170,255); }
  .joy-btn:active,
  .joy-btn.on   { background: rgb(68,170,255); color: rgb(0,0,0);
                  transform: scale(0.94); }
  .joy-up    { grid-column: 2; grid-row: 1; }
  .joy-left  { grid-column: 1; grid-row: 2; }
  .joy-right { grid-column: 3; grid-row: 2; }
  .joy-down  { grid-column: 2; grid-row: 3; }
  .joy-center { grid-column: 2; grid-row: 2;
                background: rgb(20,20,20);
                border-color: rgb(50,50,50);
                font-size: 12px; color: rgb(120,120,120);
                cursor: pointer; }
  .joy-center:hover { background: rgb(30,30,30);
                      border-color: rgb(68,170,255);
                      color: rgb(68,170,255); }
  .joy-center:active { background: rgb(68,170,255); color: rgb(0,0,0); }

  .joy-presets { display: flex; gap: 6px; flex-wrap: wrap;
                 justify-content: center; }
  .joy-preset { padding: 8px 14px; background: rgb(42,42,42);
                border: 1px solid rgb(68,68,68); color: rgb(238,238,238);
                border-radius: 8px; cursor: pointer; font-size: 13px;
                font-family: inherit; touch-action: manipulation; }
  .joy-preset:hover { background: rgb(58,58,58);
                      border-color: rgb(68,170,255); }
  .joy-preset:active { background: rgb(68,170,255); color: rgb(0,0,0); }

  /* Мобильный / узкий экран: видео сверху, серво снизу */
  @media (max-width: 720px) {
    .main { grid-template-columns: 1fr; }
    .video-panel { min-height: 45vh; }
    .servo-panel { min-height: auto; }
  }
</style>
</head>
<body>

<header>
  <span class="brand">ESP32-S3 FPV</span>
  <span class="rssi" id="rssi">— dBm</span>
</header>

<div class="main">

  <!-- ЛЕВАЯ ПАНЕЛЬ: ВИДЕО -->
  <div class="video-panel">
    <div class="video-title">Камера</div>
    <div class="video-wrap">
      <img id="stream" src="http://192.168.4.1:81/stream" alt="FPV">
    </div>
    <div class="video-status">
      <span>FPS: <span class="val" id="fps">—</span></span>
      <span>PAN: <span class="val" id="angleBigVideo">90°</span></span>
    </div>
  </div>

  <!-- ПРАВАЯ ПАНЕЛЬ: СЕРВО -->
  <div class="servo-panel">
    <div class="servo-title">Управление камерой</div>
    <div class="servo-angle-big" id="angleBig">90°</div>

    <div class="joystick">
      <button class="joy-btn joy-up"    data-dir="-1">▲</button>
      <button class="joy-btn joy-left"  data-dir="-1">◀</button>
      <button class="joy-btn joy-center" id="btnHome">90°</button>
      <button class="joy-btn joy-right" data-dir="+1">▶</button>
      <button class="joy-btn joy-down"  data-dir="+1">▼</button>
    </div>

    <div class="joy-presets">
      <button class="joy-preset" data-angle="0">0°</button>
      <button class="joy-preset" data-angle="45">45°</button>
      <button class="joy-preset" data-angle="90">90°</button>
      <button class="joy-preset" data-angle="135">135°</button>
      <button class="joy-preset" data-angle="180">180°</button>
    </div>
  </div>

</div>

<script>
// ===== Состояние =====
var angle = 90;

var angleBig      = document.getElementById('angleBig');
var angleBigVideo = document.getElementById('angleBigVideo');
var fpsEl         = document.getElementById('fps');
var rssiEl        = document.getElementById('rssi');

function clamp(v, lo, hi) { return Math.max(lo, Math.min(hi, v)); }

function updateUI(a) {
  angle = a;
  if (angleBig)      angleBig.textContent = a + '\u00B0';
  if (angleBigVideo) angleBigVideo.textContent = a + '\u00B0';
}

// ===== Отправка на серво =====
// dir = -1 (влево/вниз), +1 (вправо/вверх)
function sendStep(dir) {
  var url;
  if (dir === -1) url = '/move?dir=left';
  else            url = '/move?dir=right';
  fetch(url)
    .then(function(r){ return r.json(); })
    .then(function(d){ updateUI(d.angle); })
    .catch(function(){});
}

// Пресет — сразу на угол
function sendPreset(a) {
  // Через /move двигаем по 1°, но у нас нет прямого эндпоинта.
  // Используем /jump с шагом 10 и /move для остатка — но проще сделать прямые
  // запросы: сначала добегаем jump'ами, потом точной подгонкой.
  // Всё решается на сервере — добавим /set?angle=.
  // Пока fallback: жать до нужного угла не будем, отправим /set (см. main.ino)
  fetch('/set?angle=' + a)
    .then(function(r){ return r.json(); })
    .then(function(d){ updateUI(d.angle); })
    .catch(function(){});
}

function sendHome() {
  fetch('/home')
    .then(function(r){ return r.json(); })
    .then(function(d){ updateUI(d.angle); })
    .catch(function(){});
}

// ===== Кнопки джойстика =====
var holdTimer = null;
var holdBtn = null;

function startHold(btn, dir) {
  if (btn) btn.classList.add('on');
  holdBtn = btn;
  sendStep(dir);
  stopHold();
  holdTimer = setInterval(function(){ sendStep(dir); }, 60);
}
function stopHold() {
  if (holdTimer) { clearInterval(holdTimer); holdTimer = null; }
  if (holdBtn)   { holdBtn.classList.remove('on'); holdBtn = null; }
}

document.querySelectorAll('.joy-btn[data-dir]').forEach(function(btn){
  var dir = parseInt(btn.dataset.dir, 10);
  btn.addEventListener('mousedown',  function(e){ e.preventDefault(); startHold(btn, dir); });
  btn.addEventListener('mouseup',    stopHold);
  btn.addEventListener('mouseleave', stopHold);
  btn.addEventListener('touchstart', function(e){ e.preventDefault(); startHold(btn, dir); }, {passive:false});
  btn.addEventListener('touchend',   function(e){ e.preventDefault(); stopHold(); }, {passive:false});
  btn.addEventListener('touchcancel', stopHold);
});

document.getElementById('btnHome').addEventListener('click', sendHome);

document.querySelectorAll('.joy-preset').forEach(function(btn){
  btn.addEventListener('click', function(){
    sendPreset(parseInt(btn.dataset.angle, 10));
  });
});

// Клавиатура
document.addEventListener('keydown', function(e){
  if (e.repeat) return;
  if (e.key === 'ArrowLeft')  sendStep(-1);
  if (e.key === 'ArrowRight') sendStep(+1);
  if (e.key === 'Home')       sendHome();
});

// ===== Поллинг статуса =====
fetch('/angle').then(function(r){ return r.json(); }).then(function(d){ updateUI(d.angle); }).catch(function(){});

setInterval(function(){
  fetch('/status')
    .then(function(r){ return r.json(); })
    .then(function(j){
      if (j.fps !== undefined && fpsEl) fpsEl.textContent = j.fps;
      if (j.clients !== undefined && rssiEl) rssiEl.textContent = j.clients + ' кл.';
    })
    .catch(function(){});
}, 1500);
</script>

</body>
</html>)CAMHTML";
