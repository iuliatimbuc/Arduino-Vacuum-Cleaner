#ifndef HTMLPAGE_H
#define HTMLPAGE_H

const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ASPIRATOR</title>
  <style>
    * {
      margin: 0;
      padding: 0;
      box-sizing: border-box;
    }
    
    body {
      font-family: Arial, sans-serif;
      background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
      display: flex;
      justify-content: center;
      align-items: center;
      min-height: 100vh;
      padding: 10px;
    }
    
    .container {
      width: 100%;
      max-width: 350px;
    }
    
    h1 {
      text-align: center;
      color: white;
      margin-bottom: 30px;
      font-size: 32px;
      text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
    }
    
    .controls {
      display: grid;
      grid-template-columns: 1fr 1fr 1fr;
      gap: 10px;
    }
    
    button {
      padding: 25px 10px;
      font-size: 16px;
      border: none;
      border-radius: 12px;
      cursor: pointer;
      transition: all 0.2s;
      background: #1a1a1a;
      color: white;
      font-weight: bold;
      box-shadow: 0 4px 6px rgba(0,0,0,0.3);
    }
    
    button:active:not(.btn-stop) {
      background: #00cc00;
      transform: scale(0.95);
    }
    
    .btn-stop {
      background: #1a1a1a;
    }
    
    .btn-stop:active {
      background: #ff0000;
      transform: scale(0.95);
    }
    
    .btn-up {
      grid-column: 2;
    }
    
    .btn-left {
      grid-column: 1;
      grid-row: 2;
    }
    
    .btn-stop {
      grid-column: 2;
      grid-row: 2;
    }
    
    .btn-right {
      grid-column: 3;
      grid-row: 2;
    }
    
    .btn-down {
      grid-column: 2;
      grid-row: 3;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>ASPIRATOR</h1>
    
    <div class="controls">
      <button class="btn-up" onclick="sendCommand('fata')">ÎNAINTE</button>
      <button class="btn-left" onclick="sendCommand('stanga')">STÂNGA</button>
      <button class="btn-stop" onclick="sendCommand('stop')">STOP</button>
      <button class="btn-right" onclick="sendCommand('dreapta')">DREAPTA</button>
      <button class="btn-down" onclick="sendCommand('spate')">ÎNAPOI</button>
    </div>
  </div>

  <script>
    function sendCommand(cmd) {
      fetch('/' + cmd);
    }
  </script>
</body>
</html>
)rawliteral";

#endif