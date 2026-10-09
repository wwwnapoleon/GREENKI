<!DOCTYPE html>
<html lang="ru">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>FPV-зрение · GreenLoop</title>
  <link rel="icon" href="data:image/svg+xml,<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 100 100'><text y='.9em' font-size='90'>📹</text></svg>">
  <link rel="preconnect" href="https://fonts.googleapis.com">
  <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
  <link href="https://fonts.googleapis.com/css2?family=Manrope:wght@400;500;600;700;800&family=JetBrains+Mono:wght@400;500;700&display=swap" rel="stylesheet">
  <link rel="stylesheet" href="css/style.css">
  <link rel="stylesheet" href="css/redesign.css">

  <style>
    /* ===== СЕТКА: ЛЕВО — КОНТЕНТ, ПРАВО — СЕРВО ===== */
    .fpv-layout {
      display: grid;
      grid-template-columns: minmax(0, 1fr) 320px;
      gap: 1.5rem;
      align-items: start;
      max-width: 1400px;
      margin: 0 auto;
      padding: 1.5rem;
    }

    /* Правая колонка «прилипает» при скролле */
    .fpv-servo-panel {
      position: sticky;
      top: 1.5rem;
      background: var(--card-bg, #fff);
      border: 1px solid var(--border-color, #e5e7eb);
      border-radius: 16px;
      padding: 1.25rem;
      box-shadow: 0 4px 20px rgba(0, 0, 0, .06);
    }

    .fpv-servo-panel h3 {
      margin: 0 0 .35rem;
      font-size: 1.05rem;
      display: flex;
      align-items: center;
      gap: .5rem;
    }

    .fpv-servo-panel .servo-desc {
      margin: 0 0 1rem;
      font-size: .82rem;
      color: var(--text-muted, #6b7280);
      line-height: 1.4;
    }

    /* ===== ДЖОЙСТИК ===== */
    .servo-joystick {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      grid-template-rows: repeat(3, 1fr);
      gap: .5rem;
      max-width: 240px;
      margin: 0 auto 1rem;
      aspect-ratio: 1 / 1;
    }

    .servo-btn {
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      gap: .15rem;
      border: 1px solid var(--border-color, #e5e7eb);
      border-radius: 12px;
      background: var(--btn-bg, #f9fafb);
      color: var(--text-color, #111827);
      font-family: inherit;
      font-size: 1.4rem;
      font-weight: 600;
      cursor: pointer;
      user-select: none;
      transition: background .15s, transform .1s, box-shadow .15s;
      -webkit-tap-highlight-color: transparent;
    }

    .servo-btn:hover {
      background: var(--btn-hover, #f3f4f6);
      box-shadow: 0 2px 8px rgba(0, 0, 0, .08);
    }

    .servo-btn:active,
    .servo-btn.is-active {
      background: var(--accent, #10b981);
      color: #fff;
      transform: scale(.95);
    }

    .servo-btn:disabled {
      opacity: .4;
      cursor: not-allowed;
      transform: none;
    }

    .servo-btn .servo-label {
      font-size: .6rem;
      font-weight: 600;
      letter-spacing: .02em;
      text-transform: uppercase;
      opacity: .7;
    }

    /* Позиции в сетке 3×3 */
    .servo-up    { grid-area: 1 / 2 / 2 / 3; }
    .servo-left  { grid-area: 2 / 1 / 3 / 2; }
    .servo-stop  { grid-area: 2 / 2 / 3 / 3; font-size: 1rem; }
    .servo-right { grid-area: 2 / 3 / 3 / 4; }
    .servo-down  { grid-area: 3 / 2 / 4 / 3; }

    /* Центральная кнопка «стоп» — другого цвета */
    .servo-stop {
      background: #fee2e2;
      color: #b91c1c;
      border-color: #fecaca;
    }
    .servo-stop:hover {
      background: #fecaca;
    }
    .servo-stop:active,
    .servo-stop.is-active {
      background: #ef4444;
      color: #fff;
    }

    /* ===== СТАТУС И УГОЛ ===== */
    .servo-status {
      display: flex;
      align-items: center;
      justify-content: space-between;
      gap: .5rem;
      font-size: .8rem;
      padding: .5rem .75rem;
      border-radius: 10px;
      background: var(--surface-2, #f3f4f6);
      margin-bottom: .75rem;
    }

    .servo-status .dot {
      width: 8px;
      height: 8px;
      border-radius: 50%;
      background: #9ca3af;
      display: inline-block;
      margin-right: .35rem;
    }
    .servo-status.online .dot { background: #10b981; }
    .servo-status.offline .dot { background: #ef4444; }

    .servo-angle {
      font-family: 'JetBrains Mono', monospace;
      font-weight: 700;
      font-size: .95rem;
    }

    /* ===== ПРЕСЕТЫ ===== */
    .servo-presets {
      display: grid;
      grid-template-columns: repeat(3, 1fr);
      gap: .4rem;
      margin-top: .75rem;
    }

    .servo-preset {
      padding: .45rem .25rem;
      border: 1px solid var(--border-color, #e5e7eb);
      border-radius: 8px;
      background: var(--btn-bg, #f9fafb);
      font-family: 'JetBrains Mono', monospace;
      font-size: .72rem;
      font-weight: 600;
      cursor: pointer;
      transition: background .15s;
    }
    .servo-preset:hover { background: var(--btn-hover, #f3f4f6); }
    .servo-preset:active { background: var(--accent, #10b981); color: #fff; }

    /* ===== АДАПТИВ ===== */
    @media (max-width: 900px) {
      .fpv-layout {
        grid-template-columns: 1fr;
        padding: 1rem;
      }
      .fpv-servo-panel {
        position: static;
        order: -1; /* на мобильных управление сверху */
      }
      .servo-joystick {
        max-width: 200px;
      }
    }
  </style>
</head>
<body class="fpv-page">

  <header class="topbar">
    <a href="project-page.html" class="btn-back">← Назад</a>
    <div class="brand">
      <span class="logo-icon">📹</span>
      <span>FPV-зрение · GreenLoop</span>
    </div>
    <div class="topbar-actions">
      <span id="user-role" class="role-badge">…</span>
      <button id="logout-btn" class="btn-logout" style="display:none;">Выйти</button>
    </div>
  </header>

  <!-- ============================================================ -->
  <!-- ДВУХКОЛОНОЧНЫЙ МАКЕТ                                          -->
  <!-- ============================================================ -->
  <div class="fpv-layout">

    <!-- ===================== ЛЕВАЯ КОЛОНКА ===================== -->
    <main class="fpv-main">

      <h1>📹 FPV-зрение для экологических роботов</h1>
      <p class="lead">
        Программный продукт на базе <strong>ESP32-S3 + Wi-Fi</strong>:
        прямая трансляция, управление серво и интеграция с базой данных.
        Работает в браузере, без сторонних приложений.
      </p>

      <!-- ТАБЫ -->
      <div class="fpv-tabs" role="tablist">
        <button class="fpv-tab active" data-tab="live" role="tab">📡 Живая камера</button>
        <button class="fpv-tab" data-tab="connect" role="tab">🔌 Как подключиться</button>
        <button class="fpv-tab" data-tab="demo" role="tab">🎬 Демо FPV-зрения</button>
      </div>

      <!-- ВКЛАДКА 1: ЖИВАЯ КАМЕРА -->
      <div class="fpv-tab-content" id="tab-live">

        <div class="fpv-launch-card">
          <div class="fpv-launch-icon"></div>
          <h2>Прямой эфир</h2>
          <p class="fpv-launch-desc">
            FPV-поток с ESP32-S3. Работает <strong>только в локальной сети</strong>
            <code>RGB_Route</code> — это ограничение железа, а не программы.
          </p>

          <div class="fpv-launch-actions">
            <a href="http://192.168.100.7" target="_blank" class="btn btn-primary btn-lg">
              📹 Открыть камеру
            </a>
            <button type="button" class="btn btn-ghost" id="toggle-instruction">
              ❓ Как подключиться?
            </button>
          </div>

          <div class="fpv-launch-instruction" id="fpv-instruction" hidden>
            <h4>📱 Что нужно</h4>
            <ol>
              <li>
                Подключитесь к Wi-Fi <strong>RGB_Route</strong>
                <span class="hint-badge">2.4 ГГц</span>
              </li>
              <li>
                Пароль:
                <code>1234567890</code>
                <button type="button" class="copy-btn" data-copy="1234567890" title="Скопировать">📋</button>
              </li>
              <li>Откройте в браузере <code>192.168.100.7</code> — увидите прямой эфир.</li>
            </ol>
            <p class="fpv-tip">
              💡 Если камера не открывается — проверьте, что вы в сети <strong>RGB_Route</strong>,
              и обновите страницу.
            </p>
          </div>
        </div>

        <!-- Панель быстрых действий — ТОЛЬКО ДЛЯ АДМИНА -->
        <div class="fpv-quick-actions" id="admin-actions" style="display:none;">
          <a href="http://192.168.100.7/capture" target="_blank" class="btn">
            📸 Сделать снимок
          </a>
          <a href="http://192.168.100.7:81/status" target="_blank" class="btn">
            📊 Статус камеры
          </a>
        </div>

        <div class="project-block">
          <div class="project-block-header">
            <div class="project-block-icon">🧠</div>
            <div><h3>Что даёт FPV-зрение</h3></div>
          </div>
          <ul class="about-list">
            <li>👁️ Взгляд изнутри — там, где человек не поместится</li>
            <li>⚡ Реакция в реальном времени — без задержек</li>
            <li>🎛️ Управление серво — поворот камеры из браузера</li>
            <li>🗄️ Интеграция с БД — данные и видео в одном интерфейсе</li>
            <li>💰 Дешевле аналогов — ESP32-S3 вместо IP-камеры</li>
          </ul>
        </div>

      </div>

      <!-- ВКЛАДКА 2: КАК ПОДКЛЮЧИТЬСЯ -->
      <div class="fpv-tab-content" id="tab-connect" hidden>

        <div class="fpv-launch-card">
          <div class="fpv-launch-icon"></div>
          <h2>Подключение к камере</h2>
          <p class="fpv-launch-desc">
            Пошаговая демонстрация: от Wi-Fi до живой картинки в браузере.
          </p>

          <video controls preload="metadata" playsinline
                 style="width:100%; border-radius:12px; margin-top:1rem; background:#000;">
            <source src="videos/fpv-connect.mp4" type="video/mp4">
            Ваш браузер не поддерживает видео.
          </video>

          <div class="fpv-launch-instruction" style="margin-top:1.25rem;">
            <h4>📱 Что нужно</h4>
            <ol>
              <li>Подключитесь к Wi-Fi <strong>RGB_Route</strong> <span class="hint-badge">2.4 ГГц</span></li>
              <li>Пароль: <code>1234567890</code></li>
              <li>Откройте <code>192.168.100.7</code> в браузере</li>
              <li>Управляйте камерой и снимайте кадры</li>
            </ol>
          </div>
        </div>

      </div>

      <!-- ВКЛАДКА 3: ДЕМО FPV-ЗРЕНИЯ -->
      <div class="fpv-tab-content" id="tab-demo" hidden>

        <div class="fpv-launch-card">
          <div class="fpv-launch-icon"></div>
          <h2>FPV-зрение в работе</h2>
          <p class="fpv-launch-desc">
            Как камера помогает контролировать процесс работы агрегата
            в реальном времени со стороны (в начальной версии).
          </p>

          <video controls preload="metadata" playsinline
                 style="width:100%; border-radius:12px; margin-top:1rem; background:#000;">
            <source src="videos/fpv-process.mp4" type="video/mp4">
            Ваш браузер не поддерживает видео.
          </video>
        </div>

        <div class="project-block">
          <div class="project-block-header">
            <div class="project-block-icon">📋</div>
            <div><h3>Что показывает запись</h3></div>
          </div>
          <ul class="about-list">
            <li>👁️ Взгляд изнутри агрегата — недоступен человеку</li>
            <li>🔥 Контроль нагрева и экструзии в реальном времени</li>
            <li>🎛️ Управление серво — поворот камеры под нужным углом</li>
            <li>🗄️ Связка «видео + данные» в одном интерфейсе</li>
          </ul>
        </div>

      </div>

    </main>

    <!-- ===================== ПРАВАЯ КОЛОНКА: СЕРВО ===================== -->
    <aside class="fpv-servo-panel" aria-label="Управление серво">
      <h3>🎛️ Управление серво</h3>
      <p class="servo-desc">
        Поворот камеры по горизонтали и вертикали.
        Работает только при подключении к сети <code>RGB_Route</code>.
      </p>

      <!-- Статус + текущий угол -->
      <div class="servo-status offline" id="servo-status">
        <span><span class="dot"></span><span id="servo-status-text">Не подключено</span></span>
        <span class="servo-angle" id="servo-angle">—°</span>
      </div>

      <!-- Джойстик 3×3 -->
      <div class="servo-joystick" role="group" aria-label="Джойстик управления серво">

        <button type="button" class="servo-btn servo-up"
                data-dir="up" aria-label="Вверх">
          ▲<span class="servo-label">Вверх</span>
        </button>

        <button type="button" class="servo-btn servo-left"
                data-dir="left" aria-label="Влево">
          ◀<span class="servo-label">Влево</span>
        </button>

        <button type="button" class="servo-btn servo-stop"
                data-dir="stop" aria-label="Стоп">
          ⏹<span class="servo-label">Стоп</span>
        </button>

        <button type="button" class="servo-btn servo-right"
                data-dir="right" aria-label="Вправо">
          ▶<span class="servo-label">Вправо</span>
        </button>

        <button type="button" class="servo-btn servo-down"
                data-dir="down" aria-label="Вниз">
          ▼<span class="servo-label">Вниз</span>
        </button>

      </div>

      <!-- Пресеты углов -->
      <div class="servo-presets">
        <button type="button" class="servo-preset" data-angle="0">0°</button>
        <button type="button" class="servo-preset" data-angle="45">45°</button>
        <button type="button" class="servo-preset" data-angle="90">90°</button>
        <button type="button" class="servo-preset" data-angle="135">135°</button>
        <button type="button" class="servo-preset" data-angle="180">180°</button>
        <button type="button" class="servo-preset" data-angle="center">Центр</button>
      </div>
    </aside>

  </div>

  <script src="https://cdn.jsdelivr.net/npm/@supabase/supabase-js@2"></script>
  <script src="js/config.js"></script>
  <script src="js/auth.js"></script>
  <script>
    // ---- ТАБЫ ----
    (function() {
      var tabs = document.querySelectorAll('.fpv-tab');
      var contents = document.querySelectorAll('.fpv-tab-content');
      tabs.forEach(function(tab) {
        tab.addEventListener('click', function() {
          tabs.forEach(function(t) { t.classList.remove('active'); });
          contents.forEach(function(c) { c.setAttribute('hidden', ''); });
          tab.classList.add('active');
          var target = document.getElementById('tab-' + tab.dataset.tab);
          if (target) target.removeAttribute('hidden');
        });
      });
    })();

    // ---- РАСКРЫВАЮЩАЯСЯ ИНСТРУКЦИЯ + КОПИРОВАНИЕ ПАРОЛЯ ----
    (function() {
      var toggleBtn = document.getElementById('toggle-instruction');
      var block     = document.getElementById('fpv-instruction');
      if (toggleBtn && block) {
        toggleBtn.addEventListener('click', function() {
          if (block.hasAttribute('hidden')) {
            block.removeAttribute('hidden');
            toggleBtn.textContent = '❌ Скрыть инструкцию';
          } else {
            block.setAttribute('hidden', '');
            toggleBtn.textContent = '❓ Как подключиться?';
          }
        });
      }

      document.querySelectorAll('.copy-btn').forEach(function(btn) {
        btn.addEventListener('click', function() {
          var text = btn.getAttribute('data-copy');
          navigator.clipboard.writeText(text).then(function() {
            var old = btn.textContent;
            btn.textContent = '✅';
            setTimeout(function() { btn.textContent = old; }, 1200);
          });
        });
      });
    })();

    // ---- АВТОРИЗАЦИЯ ----
    (async function init() {
      var admin = null;
      try {
        if (typeof getAdminUser === 'function') admin = await getAdminUser();
      } catch(e) {}

      var isRealAdmin = admin && admin.email;

      var roleEl = document.getElementById('user-role');
      var logoutBtn = document.getElementById('logout-btn');
      var adminActions = document.getElementById('admin-actions');

      if (isRealAdmin) {
        if (roleEl) roleEl.textContent = '👑 ' + admin.email;
        document.body.classList.remove('is-guest');
        document.body.classList.add('is-admin');

        if (logoutBtn) {
          logoutBtn.style.display = 'inline-flex';
          logoutBtn.addEventListener('click', function() {
            if (typeof logoutAdmin === 'function') logoutAdmin();
          });
        }

        if (adminActions) adminActions.style.display = 'flex';

      } else {
        if (roleEl) roleEl.textContent = '👀 Гость (только просмотр)';
        document.body.classList.remove('is-admin');
        document.body.classList.add('is-guest');

        if (logoutBtn) logoutBtn.style.display = 'none';
        if (adminActions) adminActions.style.display = 'none';
      }
    })();

    // ============================================================
    // УПРАВЛЕНИЕ СЕРВО
    // ============================================================
    (function() {
      var ESP32_BASE = 'http://192.168.100.7';   // адрес ESP32-S3
      var statusEl     = document.getElementById('servo-status');
      var statusTextEl = document.getElementById('servo-status-text');
      var angleEl      = document.getElementById('servo-angle');

      var state = {
        horizontal: 90,   // 0..180
        vertical:   90,   // 0..180
        online:     false
      };

      // ---- Отправка команды на ESP32 ----
      // Ожидаемый эндпоинт на прошивке:
      //   /servo?h=90&v=90   → устанавливает углы
      //   /servo?dir=up      → шаг вверх
      //   /servo?dir=stop    → остановка
      // При необходимости замените URL на свой.
      function sendServoCommand(params) {
        var url = ESP32_BASE + '/servo?' + new URLSearchParams(params).toString();

        // fetch с таймаутом, чтобы не «висло» при отсутствии сети
        var controller = new AbortController();
        var timer = setTimeout(function() { controller.abort(); }, 1500);

        return fetch(url, { mode: 'no-cors', signal: controller.signal })
          .then(function() {
            clearTimeout(timer);
            setOnline(true);
            return true;
          })
          .catch(function() {
            clearTimeout(timer);
            setOnline(false);
            return false;
          });
      }

      function setOnline(online) {
        state.online = online;
        statusEl.classList.toggle('online', online);
        statusEl.classList.toggle('offline', !online);
        statusTextEl.textContent = online ? 'Подключено' : 'Не подключено';
      }

      function updateAngleUI() {
        angleEl.textContent = state.horizontal + '° / ' + state.vertical + '°';
      }

      // ---- Обработка кнопок-джойстика ----
      document.querySelectorAll('.servo-btn').forEach(function(btn) {
        var dir = btn.dataset.dir;

        function press(e) {
          e.preventDefault();
          btn.classList.add('is-active');

          if (dir === 'stop') {
            sendServoCommand({ dir: 'stop' });
            return;
          }

          // локально меняем угол и отправляем на ESP32
          var step = 10;
          if (dir === 'left')  state.horizontal = Math.max(0,   state.horizontal - step);
          if (dir === 'right') state.horizontal = Math.min(180, state.horizontal + step);
          if (dir === 'up')    state.vertical   = Math.min(180, state.vertical   + step);
          if (dir === 'down')  state.vertical   = Math.max(0,   state.vertical   - step);

          updateAngleUI();
          sendServoCommand({ h: state.horizontal, v: state.vertical });
        }

        function release() {
          btn.classList.remove('is-active');
        }

        btn.addEventListener('mousedown', press);
        btn.addEventListener('mouseup', release);
        btn.addEventListener('mouseleave', release);
        btn.addEventListener('touchstart', press, { passive: false });
        btn.addEventListener('touchend', release);
        btn.addEventListener('touchcancel', release);
      });

      // ---- Пресеты углов ----
      document.querySelectorAll('.servo-preset').forEach(function(btn) {
        btn.addEventListener('click', function() {
          var val = btn.dataset.angle;
          if (val === 'center') {
            state.horizontal = 90;
            state.vertical   = 90;
          } else {
            state.horizontal = parseInt(val, 10);
          }
          updateAngleUI();
          sendServoCommand({ h: state.horizontal, v: state.vertical });
        });
      });

      // ---- Проверка связи при загрузке ----
      (function ping() {
        var controller = new AbortController();
        var timer = setTimeout(function() { controller.abort(); }, 1500);

        fetch(ESP32_BASE + '/status', { mode: 'no-cors', signal: controller.signal })
          .then(function() { clearTimeout(timer); setOnline(true); })
          .catch(function() { clearTimeout(timer); setOnline(false); });
      })();

      updateAngleUI();

      // Экспорт в глобальную область — чтобы можно было вызвать из консоли
      window.ServoControl = {
        set: function(h, v) {
          state.horizontal = Math.min(180, Math.max(0, h));
          state.vertical   = Math.min(180, Math.max(0, v));
          updateAngleUI();
          return sendServoCommand({ h: state.horizontal, v: state.vertical });
        },
        state: state
      };
    })();
  </script>

</body>
</html>
