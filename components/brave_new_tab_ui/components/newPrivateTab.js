/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this file,
* You can obtain one at http://mozilla.org/MPL/2.0/. */

const React = require('react')

// Components
const {
  Page,
  Grid,
  Column,
  MediaContent,
  BoxedContent,
  Heading,
  Paragraph,
  SwitchButton,
  Clock
} = require('brave-ui')

const Stats = require('./stats')

// Assets
require('../../fonts/muli.css')
require('../../fonts/poppins.css')

// Images
const privateTabIcon = require('../../img/newtab/private_tab_pagearea_icon.svg')

class NewPrivateTab extends React.PureComponent {
  render () {
    const { stats } = this.props

    // do not render if stats aren't loaded yet
    if (!stats) {
      return null
    }

    return (
      <div>
        <Page style={{
          fontFamily: '"Poppins", sans-serif',
          color: 'rgba(255,255,255,0.8)',
          padding: '80px 60px 40px',
          background: 'linear-gradient(#4b3c6e, #000)'
        }}>
          <Grid columns={3}>
            <Column size={2}>
              <Stats stats={stats} />
            </Column>
            <Column size={1} align='flex-end'>
              <Clock color='#fff' />
            </Column>
          </Grid>
          <BoxedContent width='650px' margin='60px auto 0'>
            <MediaContent media={privateTabIcon} mediaSize='80px' gap='25px'>
              <Heading
                level={1}
                weight='thin'
                color='#fff'
                text={window.loadTimeData.getString('privateNewTabTitle')} />
              <div style={{fontFamily: '"Muli", sans-serif', color: '#fff'}}>
                <Paragraph
                  size='18px'
                  text={window.loadTimeData.getString('privateNewTabDisclaimer1')} />
                <Paragraph
                  italic
                  size='15px'
                  text={window.loadTimeData.getString('privateNewTabDisclaimer2')} />
                <BoxedContent margin='40px 0 25px'>
                  <SwitchButton
                    id='togglePrivateSearchEngine'
                    size='large'
                    checked={false /* TODO: enable search engine change */}
                    rightText={window.loadTimeData.getString('privateNewTabSearchLabel')} />
                </BoxedContent>
                <Paragraph
                  size='18px'
                  text={window.loadTimeData.getString('duckduckGoSearchInfo')} />
              </div>
            </MediaContent>
          </BoxedContent>
        </Page>
      </div>
    )
  }
}

module.exports = NewPrivateTab
