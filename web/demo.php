<?php
    $max_machines = 5;

    $name = $loc = $pin = $status = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["txtName"];
        //$loc = test_input($_POST["txtLocation"]);
        //$pin = test_input($_POST["numPin"]);
        //$stat = test_input($_POST["numStatus"]);
        print "Hello there\n";
      }
      
      function test_input($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
      }
?>
<form method="post" action="/cgi-bin/output.o">
    Name:       <input type="text"   name="txtName"     id="mName"/> <br>
    Location:   <input type="text"   name="txtLocation" id="mLoc" /> <br>
    Pin:        <input type="number" name="numPin"      id="mPin"   min="0" max="27"/> <br>
    Status:     <input type="status" name="numStatus"   id="mStat"  min="0" max="1"/> <br>

    <input type="submit" name="btnSendUpdate" value="Add Machine" />
</form>
