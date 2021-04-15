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

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?> "
    <input type="submit" class="button" name="btnAddMachine" value="Add Machine" />
    Machine Number:
    <input type="number" name="numMachine"  id="mNum" min="1" max="5"/> <br>
    <input type="submit" name="btnDelete" value="Delete Machine" />
    <input type="submit" name="btnUpdate" value="Update Machine" />
</form>

<?php
?>

<form method="post" action="/cgi-bin/output test">
    Name:       <input type="text"   name="txtName"     id="mName"/> <br>
    Location:   <input type="text"   name="txtLocation" id="mLoc" /> <br>
    Pin:        <input type="number" name="numPin"      id="mPin"   min="0" max="27"/> <br>
    Status:     <input type="status" name="numStatus"   id="mStat"  min="0" max="1"/> <br>

    <input type="submit" name="btnSendUpdate" value="Add Machine" />
</form>
