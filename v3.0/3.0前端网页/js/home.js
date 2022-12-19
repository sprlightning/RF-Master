window.addEventListener('load', getReadings);


function updateDateTime() {
  var currentdate = new Date();
  var datetime = currentdate.getDate() + "/"
    + (currentdate.getMonth() + 1) + "/"
    + currentdate.getFullYear() + " at "
    + currentdate.getHours() + ":"
    + currentdate.getMinutes() + ":"
    + currentdate.getSeconds();
  document.getElementById("update-time").innerHTML = datetime;
  console.log(datetime);
}

// Function to get current readings on the webpage when it loads for the first time
function getReadings() {
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var myObj = JSON.parse(this.responseText);
      console.log("收到数据~");
      console.log(myObj);
      document.getElementById("version").innerHTML = myObj.version;
      document.getElementById("ChipId").innerHTML = myObj.ChipId;
      document.getElementById("CpuFreqMHz").innerHTML = myObj.CpuFreqMHz;
      document.getElementById("SSID").innerHTML = myObj.SSID;
      document.getElementById("IP").innerHTML = myObj.IP;
      document.getElementById("gateway").innerHTML = myObj.gateway;
      document.getElementById("DNS").innerHTML = myObj.DNS;
      document.getElementById("APMAC").innerHTML = myObj.APMAC;
      document.getElementById("STAMAC").innerHTML = myObj.STAMAC;
      document.getElementById("Uptime").innerHTML = myObj.Uptime;
      document.getElementById("SketchSize").innerHTML = myObj.SketchSize;
      document.getElementById("SketchSpace").innerHTML = myObj.SketchSpace;
      document.getElementById("usedBytes").innerHTML = myObj.usedBytes;
      document.getElementById("available").innerHTML = myObj.available;
      document.getElementById("totalBytes").innerHTML = myObj.totalBytes;
      updateDateTime();
    }
  };
  xhr.open("GET", "/readings", true);
  xhr.send();
}

// Create an Event Source to listen for events
if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('open', function (e) {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function (e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('new_readings', function (e) {
    console.log("监听~ new_readings");
    console.log("new_readings", e.data);
    
    var obj = JSON.parse(e.data);
    document.getElementById("version").innerHTML = obj.version;
    document.getElementById("ChipId").innerHTML = obj.ChipId;
    document.getElementById("CpuFreqMHz").innerHTML = obj.CpuFreqMHz;
    document.getElementById("SSID").innerHTML = obj.SSID;
    document.getElementById("IP").innerHTML = obj.IP;
    document.getElementById("gateway").innerHTML = obj.gateway;
    document.getElementById("DNS").innerHTML = obj.DNS;
    document.getElementById("APMAC").innerHTML = obj.APMAC;
    document.getElementById("STAMAC").innerHTML = obj.STAMAC;
    document.getElementById("Uptime").innerHTML = obj.Uptime;
    document.getElementById("SketchSize").innerHTML = obj.SketchSize;
    document.getElementById("SketchSpace").innerHTML = obj.SketchSpace;
    document.getElementById("usedBytes").innerHTML = obj.usedBytes;
    document.getElementById("available").innerHTML = obj.available;
    document.getElementById("totalBytes").innerHTML = obj.totalBytes;
    updateDateTime();
  }, false);
}

