<?php
    $max_machines = 5;

    $name = $loc = $pin = $status = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = test_input($_POST["name"]);
        $loc = test_input($_POST["location"]);
        $pin = test_input($_POST["pin"]);
        $stat = test_input($_POST["status"]);
      }
      
      function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
      }
?>
<form method="post" action="/cgi-bin/output test">
    Name:       <input type="text"   name="txtName"     id="mName"/> <br>
    Location:   <input type="text"   name="txtLocation" id="mLoc" /> <br>
    Pin:        <input type="number" name="numPin"      id="mPin"   min="0" max="27"/> <br>
    Status:     <input type="status" name="numStatus"   id="mStat"  min="0" max="1"/> <br>

    <input type="submit" name="btnSendUpdate" value="Add Machine" />
</form>
