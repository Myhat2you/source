<?php
    $uapp = "ls -al";
    $cmd = $uapp . $_POST["pinno"] . " " . $_POST["pinval"]. '';

    echo "User Test App" . $cmd;

    $output = shell_exec($cmd);
    echo "<pre>$output</pre>";
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
    <input type="submit" class="button" name="btnAddMachine" value="Add Machine" />
    Machine Number:
    <input type="number" name="numMachine"  id="mnum" min="1" max="5"/> <br>
    <input type="submit" name="btnSendForm" value="Delete Machine" />
    <input type="submit" name="btnSendForm" value="Update Machine" />
</form>