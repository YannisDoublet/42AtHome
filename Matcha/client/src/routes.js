import React from 'react';
import {Switch, Route} from 'react-router-dom'

import Home from './components/Home'
import Layout from "./HOC/Layout";

const Routes = () => {
    return (
        <div>
            <Layout>
                <Switch>
                    <Route to={'/'} exact component={Home}/>
                </Switch>
            </Layout>
        </div>
    );
};

export default Routes