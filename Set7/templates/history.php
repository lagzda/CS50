<div class="text-center">
    <?php if (empty($positions)): ?>
        <h4>You haven't done any actions yet</h4>
    <?php else: ?>    
        <h2>Your history:</h2>
        <table class="table text-left">
            <thead>
                <tr>
                    <th>Action</th>
                    <th>Symbol</th>
                    <th>Shares</th>
                    <th>Price</th>
                    <th>Total</th>
                    <th>Date</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach($positions as $position): ?>
                    <tr>
                        <td><?= $position["action"] ?></td>
                        <td><?= $position["symbol"] ?></td>
                        <td><?= $position["shares"] ?></td>
                        <td><?= $position["price"] ?></td>
                        <td><?= $position["price"] * $position["shares"] ?>
                        <td><?= $position["date"] ?></td>
                    </tr>
                <?php endforeach ?>    
            </tbody>
        </table>
    <?php endif ?>   
</div>
