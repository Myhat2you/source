<?php
    $max_machines = 5;
    $uapp = "ls -al";
    $cmd = $uapp . $_POST["pinno"] . " " . $_POST["pinval"]. '';

    echo "User Test App" . $cmd;

    $output = shell_exec($cmd);
    echo "<pre>$output</pre>";
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
    <input type="submit" class="button" name="btnAddMachine" value="Add Machine" />
    Machine Number:
    <input type="number" name="numMachine"  id="mNum" min="1" max="5"/> <br>
    <input type="submit" name="btnDelete" value="Delete Machine" />
    <input type="submit" name="btnUpdate" value="Update Machine" />
</form>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
    <input type="text"   name="txtName"     id="mName"/> <br>
    <input type="text"   name="txtLocation" id="mLoc" /> <br>
    <input type="number" name="numPin"      id="mPin"   min="0" max="27"/> <br>
    <input type="status" name="numStatus"   id="mStat"  min="0" max="1"/> <br>

    <input type="submit" name="btnSendForm" value="Update Machine" />
</form>
